//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, a[N], s[N];
multimap<ll, ll> mp;
vector<ll> v;

int main() {
	mulT0 {
		mp.clear(); v.clear();
		scanf("%lld", &n);
		rep(i, 1, n) {
			scanf("%lld", &a[i]); s[i] = 0;
			mp.insert(make_pair(a[i], i));
		}
		sort(a+1, a+1+n);
		rep(i, 1, n) s[i] = s[i-1] + a[i];
		ll mx = n, res = a[n];
		per(i, n-1, 1) {
			ll j = upper_bound(a+1, a+1+n, a[i]) - a - 1;
			if(j != n && s[j] < a[j+1]) break;
			mx = i; res = a[i];
		}
		printf("%lld\n", n-mx+1);
		for(multimap<ll, ll>::reverse_iterator it=mp.rbegin();it!=mp.rend();it++) {
			if(it->first >= res) v.push_back(it->second);
			else break;
		}
		sort(v.begin(), v.end());
		for(vector<ll>::iterator it=v.begin();it!=v.end();it++) printf("%lld ", *it);
		puts("");
	}
	return 0;
}