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

ll n;
ll a[maxn] , b[maxn];

bool check(ll x){
	ll cur = 0;
	for(ll i = 0 ; i < n ; i++){
		if(b[i] >= cur && a[i] + cur + 1 >= x) cur++;
	}
	return (cur >= x);
}

void solve(){
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]>>b[i];
	}
	ll l = 0 , r = n + 1;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}