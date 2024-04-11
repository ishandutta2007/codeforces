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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll ans[maxn][maxn];
vector<pll> v , s;

void solve(){
	v.clear(); s.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll l , r;
		cin>>l>>r;
		v.push_back({l , -r});
		if(l == r) ans[l][l] = l;
	}
	sort(all(v));
	for(ll i = 0 ; i < n ; i++){
		pll t = {0 , 0};
		while(!s.empty()){
			if(s.back().first <= v[i].first && s.back().second <= v[i].second){
				t = s.back();
				break;
			}
			s.pop_back();
		}
		if(v[i].first == t.first){
			ans[t.first][-t.second] = -v[i].second + 1;
		} else {
			ans[t.first][-t.second] = v[i].first - 1;
		}
		s.push_back(v[i]);
	}
	for(auto p : v){
		cout<<p.first<<' '<<-p.second<<' '<<ans[p.first][-p.second]<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}