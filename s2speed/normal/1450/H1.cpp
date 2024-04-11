#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , cnt[] = {0 , 0};
	cin>>n>>m>>s;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '?'){
			m++;
			continue;
		}
		cnt[(i & 1) ^ (s[i] == 'b')]++;
	}
	ll ans = 0 , c = 1;
	cnt[0] += m;
	if(abs(cnt[0] - cnt[1]) % 4 == 0) ans = abs(cnt[0] - cnt[1]) / 4;
	for(ll i = 1 ; i <= m ; i++){
		cnt[0]--; cnt[1]++;
		c *= m - i + 1; c %= md;
		c *= tav(i , md - 2); c %= md;
		ll o = abs(cnt[0] - cnt[1]) , h = c * (o / 4) % md;
		ans += h * (o % 4 == 0);
	}
	ans %= md;
	ll h = tav(2 , m - 1);
	ans *= tav(h , md - 2); ans %= md;
	cout<<ans<<'\n';
	return 0;
}