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

const ll maxn = 1e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> a[maxn];
string s;

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = s[j] ^ '0';
		}
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		for(ll j = 0 ; j < m - 1 ; j++){
			ll h = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
			if(h == 3){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}