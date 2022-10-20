#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	register int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
const int N = 200005;
struct Nm{
	int x, p;
	bool f;
}a[N];
bool cmpx(Nm a, Nm b){return a.x > b.x;}
bool cmpp(Nm a, Nm b){return a.p < b.p;}

int main(){
	// freopen("b.in", "r", stdin);
	// freopen("b.out", "w", stdout);
	int n, m, k;
	in(n); in(m); in(k);
	for(int i=1; i<=n; i++)
		in(a[i].x), a[i].p = i;
	sort(a+1, a+1+n, cmpx);
	long long ans = 0;
	for(int i=1; i<=k*m; i++)
		a[i].f = true, ans += a[i].x;
	printf("%lld\n", ans);
	sort(a+1, a+1+n, cmpp);
	int cnt = 0, out = 0;
	for(int i=1; i<=n; i++){
		cnt += (int)(a[i].f);
		if(cnt == m){
			++out;
			if(out == k) break;
			printf("%d ", i);
			cnt = 0;
		}
	}
	puts("");
	return 0;
}