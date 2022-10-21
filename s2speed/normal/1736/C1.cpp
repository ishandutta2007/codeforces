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

ll lcm(ll a , ll b){
	ll h = a * b / gcd(a , b);
	return h;
}

ll a[maxn] , f[maxn];
vector<ll> v;

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; f[i] = i - a[i] + 1;
	}
	f[n] = inf;
	ll ans = 0;
	v.clear(); v.push_back(n);
	for(ll i = n - 1 ; ~i ; i--){
		while(!v.empty()){
			ll j = v.back();
			if(f[i] < f[j]) break;
			v.pop_back();
		}
		v.push_back(i);
		ll l = 0 , r = sze(v);
		while(l < r - 1){
			ll m = (r + l) >> 1;
			if(f[v[m]] > i){
				l = m;
			} else {
				r = m;
			}
		}
		ans += v[l] - i;
	}
	cout<<ans<<'\n';
	return;
}

/*
1
3
1 2 3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}