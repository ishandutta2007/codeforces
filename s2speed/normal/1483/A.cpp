#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 2e16;

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

ll ans[MAXN] , cnt[MAXN];
vector<ll> v[MAXN];

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll k , h;
		cin>>k;
		if(k == 1){
			cin>>h; h;
			cnt[h]++;
			ans[i] = h;
			continue;
		} else {
			for(ll j = 0 ; j < k ; j++){
				cin>>h;
				v[i].push_back(h);
			}
		}
	}
	for(ll i = 0 ; i < m ; i++){
		if(v[i].empty()) continue;
		ll o = inf , h = -1;
		for(auto j : v[i]){
			if(cnt[j] < o){
				h = j;
				o = cnt[j];
			}
		}
		ans[i] = h;
		cnt[h]++;
	}
	for(ll i = 0 ; i < m ; i++){
		v[i].clear();
	}
	ll u = (m + 1) / 2;
	for(ll i = 1 ; i <= n ; i++){
		if(cnt[i] > u){
			for(ll j = i ; j <= n ; j++){
				cnt[j] = 0;
			}
			cout<<"NO\n";
			return;
		}
		cnt[i] = 0;
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < m ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/