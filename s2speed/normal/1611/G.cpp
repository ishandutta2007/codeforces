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

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

string s[maxn];
multiset<ll> st;
vector<pll> v;

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>s[i];
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i & 1 ; j < m ; j += 2){
			if(s[i][j] ^ '0') v.push_back({i + j , i - j});
		}
	}
	sort(all(v));
	for(auto p : v){
		ll a = p.second;
		auto it = st.upper_bound(a) , et = st.begin();
		if(it != et) st.erase(--it);
		st.insert(a);
	}
	ll ans = sze(st);
	st.clear();
	v.clear();
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 1 - (i & 1) ; j < m ; j += 2){
			if(s[i][j] ^ '0') v.push_back({i + j , i - j});
		}
	}
	sort(all(v));
	for(auto p : v){
		ll a = p.second;
		auto it = st.upper_bound(a) , et = st.begin();
		if(it != et) st.erase(--it);
		st.insert(a);
	}
	ans += sze(st);
	cout<<ans<<'\n';
	st.clear();
	v.clear();
	for(ll i = 0 ; i < n ; i++) s[i].clear();
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}