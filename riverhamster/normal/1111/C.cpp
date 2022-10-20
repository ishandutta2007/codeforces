#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100005;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
int n, m;
ll A, B;
int a[N];

int find(int x){
	int l = 1, r = m, mid, ans = 0;
	while(l <= r){
		mid = (l + r) >> 1;
		if(a[mid] <= x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

ll dfs(int l, int r, int x, int y){
	// printf("DFS %d %d %d %d\n", l, r, x, y); fflush(stdout);
	// for(int i=1; i<=1000000; i++);
	if(x > y) return A;
	if(l == r) return B*(y-x+1);
	int mid = (l + r) >> 1;
	int f = find(mid);
	ll v1 = 0, v2 = 0;
	if(f != 0 && f>=x) v1 = dfs(l, mid, x, f);
	else v1 = A;
	if(f != y)  v2 = dfs(mid+1, r, f+1, y);
	else v2 = A;
	// printf("v1 = %lld v2 = %lld\n", v1, v2);
	return min(v1+v2, (ll)(y-x+1) * (ll)(r-l+1) * (ll)B);
}

int main(){
	// freopen("cf1111c.in", "r", stdin);
	// freopen("cf1111c.out", "w", stdout);
	in(n); in(m); in(A); in(B);
	for(int i=1; i<=m; i++) in(a[i]);
	sort(a+1, a+1+m);
	printf("%lld\n", dfs(1, 1<<n, 1, m));
	return 0;
}