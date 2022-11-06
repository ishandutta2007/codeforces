//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e3+5;

int T, n, p[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct BIT {
	int c[N];
	void clear() {memset(c, 0, sizeof(c));}
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k) {for(;x<=n;x+=lowbit(x)) c[x] += k;}
	int ask(int x) {int k = 0; for(;x;x-=lowbit(x)) k += c[x]; return k;}
}L, R;

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &p[i]);
		L.clear(); R.clear();
		ll ans = 0;
		rep(b, 2, n-2) {
			L.add(p[b-1], 1);
			R.clear();
			per(c, n-1, b+1) {
				R.add(p[c+1], 1);
				ans += 1LL * L.ask(p[c]) * R.ask(p[b]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}