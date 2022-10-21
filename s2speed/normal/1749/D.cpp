#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e5 + 17 , md = 998244353 , inf = 2e16;

inline ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

bitset<maxn> pr;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	pr[2] = 1; pr[3] = 1; pr[5] = 1; pr[7] = 1; pr[11] = 1; pr[13] = 1; pr[17] = 1; pr[19] = 1; pr[23] = 1; pr[29] = 1; pr[31] = 1; pr[37] = 1;
	ll n , m;
	cin>>n>>m;
	ll h = 1 , z = 1 , ans = 0 , tv = 1 , k = m % md;
	for(ll i = 1 ; i <= n ; i++){
		tv *= k; tv %= md;
		if(pr[i]) z *= i;
		ll o = (m / z) % md;
		h *= o; h %= md;
		ans += tv - h;
	}
	ans %= md; ans += (ans < 0) * md;
	cout<<ans<<'\n';
	return 0;
}