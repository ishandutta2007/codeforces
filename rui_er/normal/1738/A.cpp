//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll T, n, a[N], b[N];
vector<ll> vec0, vec1;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll calc(vector<ll>& vec0, vector<ll>& vec1) {
	ll ans = 0, x = vec0.size(), y = vec1.size();
	rep(i, 0, x-1) {
		if(i < y) {
			ans += vec1[i];
			if(i < x - 1) ans += vec0[i];
		}
	}
	return ans;
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n) scanf("%lld", &b[i]);
		rep(i, 1, n) {
			if(a[i]) vec1.push_back(b[i]);
			else vec0.push_back(b[i]);
		}
		sort(vec0.begin(), vec0.end(), greater<ll>());
		sort(vec1.begin(), vec1.end(), greater<ll>());
		ll ans = 0;
		for(ll i : vec0) ans += i;
		for(ll i : vec1) ans += i;
		printf("%lld\n", ans + max(calc(vec0, vec1), calc(vec1, vec0)));
		vec0.clear();
		vec1.clear();
	}
	return 0;
}