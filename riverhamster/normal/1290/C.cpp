#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 300005;
char s[N];
int a[N][2], cnt[N];
int sum[N][2];

int fa[N], dis[N], res[N], rsum = 0, Val[N];
pair<int, int> find(int x){
	if(fa[x] == x) return make_pair(x, 0);
	pair<int, int > res = find(fa[x]);
	dis[x] = dis[x] ^ dis[fa[x]];
	fa[x] = res.first;
	return make_pair(fa[x], dis[x]);
}
void merge(int x, int y, int dist){
	// printf("Merge %d %d [dist %d]\n", x, y, dist);
	pair<int, int> fx = find(x), fy = find(y);
	int rx = fx.first, ry = fy.first, dx = fx.second, dy = fy.second;
	dist = dist ^ dx ^ dy;
	if(rx == ry) return ;
	// printf("(rx, ry) = (%d, %d)\n", rx, ry);
	rsum -= res[rx]; rsum -= res[ry];
	fa[ry] = rx;
	dis[ry] = dist;
	// printf("dis %d\n", dis[ry]);
	// printf("dx %d dy %d dist %d\n", dx, dy, dist);
	sum[rx][0] += sum[ry][dist];
	sum[rx][1] += sum[ry][dist ^ 1];
	// printf("Sum[%d][%d] = %d Sum[%d][%d] = %d\n", rx, 0, sum[rx][0], rx, 1, sum[rx][1]);
	sum[ry][0] = sum[ry][1] = 0;
	if(Val[ry] != -1) Val[rx] = Val[ry] ^ dist;
	// printf("Val[%d] = %d\n", rx, Val[rx]);
	if(Val[rx] == -1) res[rx] = min(sum[rx][0], sum[rx][1]);
	else res[rx] = sum[rx][Val[rx]];
	rsum += res[rx];
}
void fix(int x, int val){
	// printf("Fix %d %d\n", x, val);
	pair<int, int> fx = find(x);
	int rx = fx.first, dx = fx.second;
	rsum -= res[rx];
	Val[rx] = val ^ dx;
	res[rx] = sum[rx][Val[rx]];
	rsum += res[rx];
}

int main(){
	// File("cf1290c");
	memset(Val, -1, sizeof(Val));
	int n, K;
	gi(n); gi(K);
	scanf("%s", s + 1);
	for(int i=1; i<=K; i++){
		int c; gi(c);
		for(int j=1, x; j<=c; j++)
			gi(x), a[x][cnt[x]++] = i;
	}
	for(int i=1; i<=K; i++) fa[i] = i, dis[i] = 0, res[i] = 0, sum[i][1] = 1;
	for(int i=1; i<=n; i++){
		if(cnt[i] == 1){
			fix(a[i][0], (s[i] - '0') ^ 1);
		}
		else if(cnt[i] == 2){
			merge(a[i][0], a[i][1], (s[i] - '0') ^ 1);
		}
		printf("%d\n", rsum);
	}
	return 0;
}