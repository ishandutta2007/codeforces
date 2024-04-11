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

const ll maxn = 1e6 + 16 , p = 131 , md = 2000000357 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
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

ll n , k;
ll hs[maxn] , tv[maxn];
string s;

ll get_hash(ll l , ll r){
	ll res = hs[r];
	if(l){
		ll o = 1ll * hs[l - 1] * tv[r - l + 1] % md;
		res -= o; res %= md; if(res < 0) res += md;
	}
	return res;
}

bool cmp(ll i){
	if(get_hash(i , n - 1) == get_hash(0 , n - 1 - i)) return false;
	ll l = -1 , r = n - 1 - i;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(get_hash(0 , m) == get_hash(i , m + i)){
			l = m;
		} else {
			r = m;
		}
	}
	return (s[l + 1] < s[l + 1 + i]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k>>s; n <<= 1; s += s;
	tv[0] = 1;
	for(ll i = 1 ; i < n ; i++){
		tv[i] = (1ll * tv[i - 1] * p) % md;
	}
	hs[0] = s[0];
	for(ll i = 1 ; i < n ; i++){
		hs[i] = 1ll * p * hs[i - 1] + s[i]; hs[i] %= md;
	}
	ll r = n;
	for(ll i = 1 ; i < n ; i++){
		if(cmp(i)){
			r = i;
			break;
		}
	}
	string ans;
	for(ll i = 0 ; sze(ans) < k ; i++ , i %= r){
		ans += s[i];
	}
	cout<<ans<<'\n';
	return 0;
}