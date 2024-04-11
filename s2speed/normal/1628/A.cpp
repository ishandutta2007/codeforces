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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> v[maxn] , b;
ll x[maxn] , cnt[maxn];

void solve(){
	b.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i <= n + 1 ; i++){
		x[i] = 0;
		v[i].clear();
		cnt[i] = 0;
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v[h].push_back(i);
		cnt[h]++;
	}
	ll y = 0;
	while(y < n){
		ll h = y;
		for(ll i = 0 ; i <= n + 1 ; i++){
			while(x[i] != cnt[i]){
				if(v[i][x[i]] >= y) break;
				x[i]++;
			}
			if(x[i] == cnt[i]){
				b.push_back(i);
				break;
			}
			h = max(h , v[i][x[i]]);
		}
		y = h + 1;
	}
	ll bs = sze(b);
	cout<<bs<<'\n';
	for(ll i = 0 ; i < bs ; i++){
		cout<<b[i]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}