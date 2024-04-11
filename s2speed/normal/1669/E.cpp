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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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
ll cnp[12][12] , cnt[12][2];

void solve(){
	memset(cnp , 0 , sizeof(cnp));
	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		char c , d;
		cin>>c>>d;
		ll a = c - 'a' , b = d - 'a';
		cnp[a][b]++;
		cnt[a][0]++; cnt[b][1]++;
	}
	ll ans = 0;
	for(ll i = 0 ; i < 12 ; i++){
		ll h = cnt[i][0];
		ans += h * (h - 1) / 2;
		h = cnt[i][1];
		ans += h * (h - 1) / 2;
	}
	for(ll i = 0 ; i < 12 ; i++){
		for(ll j = 0 ; j < 12 ; j++){
			ll h = cnp[i][j];
			ans -= h * (h - 1);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}