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

vector<pll> v[2];
ll p[maxn] , ans[maxn];
string s;

void solve(){
	v[0].clear(); v[1].clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>p[i];
	}
	cin>>s;
	for(ll i = 0 ; i < n ; i++){
		v[s[i] - '0'].push_back({p[i] , i});
	}
	sort(all(v[0]) , greater<pll>()); sort(all(v[1]) , greater<pll>());
	ll as = sze(v[1]) , bs = n - as;
	for(ll i = 0 ; i < as ; i++){
		ans[v[1][i].second] = i;
	}
	for(ll i = 0 ; i < bs ; i++){
		ans[v[0][i].second] = i + as;
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<n - ans[i]<<' ';
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