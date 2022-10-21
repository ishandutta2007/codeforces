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

const ll maxn = 5e5 + 16 , md = 998244353 , inf = 2e16;

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

vector<vector<ll>> a , psn , psm , sfn , sfm;
vector<vector<pll>> rsn , rsm , rfn , rfm;
bitset<maxn> b;

void solve(){
	a.clear(); psn.clear(); psm.clear(); sfn.clear(); sfm.clear(); rsn.clear(); rsm.clear(); rfn.clear(); rfm.clear();
	ll n , m;
	cin>>n>>m;
	a.resize(n); psn.resize(n); psm.resize(n); sfn.resize(n); sfm.resize(n); rsn.resize(m); rsm.resize(m); rfn.resize(m); rfm.resize(m);
	for(ll i = 0 ; i < n ; i++){
		a[i].resize(m);
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
		}
	}
	for(ll i = 0 ; i < n ; i++){
		psn[i].push_back(a[i][0]);
		for(ll j = 1 ; j < m ; j++){
			psn[i].push_back(min(psn[i][j - 1] , a[i][j]));
		}
	}
	for(ll i = 0 ; i < n ; i++){
		psm[i].push_back(a[i][0]);
		for(ll j = 1 ; j < m ; j++){
			psm[i].push_back(max(psm[i][j - 1] , a[i][j]));
		}
	}
	for(ll i = 0 ; i < n ; i++){
		sfn[i].resize(m);
		sfn[i][m - 1] = a[i][m - 1];
		for(ll j = m - 2 ; j >= 0 ; j--){
			sfn[i][j] = min(sfn[i][j + 1] , a[i][j]);
		}
	}
	for(ll i = 0 ; i < n ; i++){
		sfm[i].resize(m);
		sfm[i][m - 1] = a[i][m - 1];
		for(ll j = m - 2 ; j >= 0 ; j--){
			sfm[i][j] = max(sfm[i][j + 1] , a[i][j]);
		}
	}
	for(ll j = 0 ; j < m ; j++){
		for(ll i = 0 ; i < n ; i++){
			rsn[j].push_back({psn[i][j] , i});
		}
		sort(all(rsn[j]));
	}
	for(ll j = 0 ; j < m ; j++){
		for(ll i = 0 ; i < n ; i++){
			rsm[j].push_back({psm[i][j] , i});
		}
		sort(all(rsm[j]));
	}
	for(ll j = 0 ; j < m ; j++){
		for(ll i = 0 ; i < n ; i++){
			rfn[j].push_back({sfn[i][j] , i});
		}
		sort(all(rfn[j]));
	}
	for(ll j = 0 ; j < m ; j++){
		for(ll i = 0 ; i < n ; i++){
			rfm[j].push_back({sfm[i][j] , i});
		}
		sort(all(rfm[j]));
	}
	for(ll j = 0 ; j < m - 1 ; j++){
		ll xl = -inf , nr = inf , h = -1;
		for(ll i = 0 ; i < n - 1 ; i++){
			ll q = rsn[j][i].second;
			xl = max(xl , psm[q][j]);
			nr = min(nr , sfn[q][j + 1]);
			if(xl < rsn[j][i + 1].first && nr > rfm[j + 1][n - i - 2].first){
				h = i;
				break;
			}
		}
		if(h != -1){
			cout<<"YES\n";
			for(ll i = 0 ; i <= h ; i++){
				b[rsn[j][i].second] = true;
			}
			for(ll i = 0 ; i < n ; i++){
				cout<<(char)('R' + ('B' - 'R') * b[i]);
				b[i] = false;
			}
			cout<<' '<<j + 1<<'\n';
			return;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}