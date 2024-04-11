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

ll n , k;
ll a[maxn];
vector<ll> v;

bool check(ll x){
	ll h = 2 * x;
	for(ll i = 0 ; i < x ; i++){
		if(v[i] + v[h - i - 1] < k) return false;
	}
	return true;
}

void solve(){
	v.clear();
	ll res = 0;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		res += a[i] / k; a[i] %= k;
		v.push_back(a[i]);
	}
	sort(all(v) , greater<ll>());
	ll l = 0 , r = n / 2 + 1;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<res + l<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}