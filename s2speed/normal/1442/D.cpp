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

const ll maxn = 3e3 + 17 , md = 1e9 + 7 , inf = 2e16;

ll d[maxn];
ll ps[maxn][maxn] , a[maxn][maxn] , b[maxn][maxn];
vector<ll> v;
vector<pll> c[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k;
	for(ll i = 1 ; i <= n ; i++){
		ll t;
		cin>>t;
		v.clear();
		for(ll j = 0 ; j < t ; j++){
			ll h;
			cin>>h;
			v.push_back(h);
		}
		ll lm = min(k , t);
		for(ll j = 1 ; j <= lm ; j++){
			ps[i][j] = ps[i][j - 1] + v[j - 1];
			c[j].push_back({ps[i][j] , i});
		}
		d[i] = lm;
	}
	for(ll i = 1 ; i <= n ; i++){
		memcpy(a[i] , a[i - 1] , sizeof(a[i]));
		for(ll j = k ; j >= d[i] ; j--){
			a[i][j] = max(a[i][j] , a[i][j - d[i]] + ps[i][d[i]]);
		}
	}
	for(ll i = n ; i ; i--){
		memcpy(b[i] , b[i + 1] , sizeof(b[i]));
		for(ll j = k ; j >= d[i] ; j--){
			b[i][j] = max(b[i][j] , b[i][j - d[i]] + ps[i][d[i]]);
		}
	}
	ll ans = a[n][k];
	for(ll j = 1 ; j <= k ; j++){
		sort(all(c[j]) , greater<pll>());
		ll cur = 0;
		for(auto p : c[j]){
			ll v = p.first , i = p.second;
			if(cur > k - j) break;
			cur += d[i];
			ll h = 0;
			for(ll q = 0 ; q <= k - j ; q++){
				h = max(h , a[i - 1][q] + b[i + 1][k - j - q]);
			}
			ans = max(ans , h + v);
		}
	}
	cout<<ans<<'\n';
	return 0;
}