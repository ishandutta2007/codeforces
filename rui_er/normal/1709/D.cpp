// Problem: D. Rorororobot
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;
#define y1 y114514

ll n, m, a[N], q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct SparseTable {
	ll lg[N], mx[N][20];
	void init(ll* a, ll len) {
		lg[0] = -1;
		rep(i, 1, len) lg[i] = lg[i>>1] + 1;
		rep(i, 1, len) mx[i][0] = a[i];
		rep(j, 1, 19) rep(i, 1, len-(1<<j)+1) mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
	}
	ll qmax(ll l, ll r) {
		ll k = lg[r-l+1];
		return max(mx[l][k], mx[r-(1<<k)+1][k]); 
	}
}st;

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, m) scanf("%lld", &a[i]);
	st.init(a, m);
	for(scanf("%lld", &q);q;q--) {
		ll x1, y1, x2, y2, k;
		scanf("%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &k);
		if(y1 > y2) swap(x1, x2), swap(y1, y2);
		if(y1 % k != y2 % k) puts("NO");
		else {
			ll tmp = n - n % k + x1 % k;
			if(tmp > n) tmp -= k;
			if(x1 % k == x2 % k && tmp > st.qmax(y1, y2)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}