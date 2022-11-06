// Problem: A. Color the Picture
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const ll N = 1e5+5;

ll T, n, m, k, a[N];
vector<ll> tmp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld%lld", &n, &m, &k);
		rep(i, 1, k) scanf("%lld", &a[i]);
		ll ok = 0;
		{
			tmp.clear();
			rep(i, 1, k) if(a[i] / n > 1) tmp.push_back(a[i]/n);
			sort(tmp.begin(), tmp.end(), greater<ll>());
			ll L = 0, R = 0;
			for(ll i : tmp) {
				L += 2;
				R += i;
				ok |= L <= m && m <= R;
			}
		}
		{
			tmp.clear();
			rep(i, 1, k) if(a[i] / m > 1) tmp.push_back(a[i]/m);
			sort(tmp.begin(), tmp.end(), greater<ll>());
			ll L = 0, R = 0;
			for(ll i : tmp) {
				L += 2;
				R += i;
				ok |= L <= n && n <= R;
			}
		}
		puts(ok?"Yes":"No");
	}
	return 0;
}