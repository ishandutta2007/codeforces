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

vector<ll> v;

void solve(){
	v.clear();
	ll n , k;
	cin>>n>>k;
	if(n == 4 && k == 3){
		cout<<"-1\n";
		return;
	}
	ll o = n - 1 , lm = n >> 1;
	for(ll i = 0 ; i < n ; i++){
		v.push_back(i);
	}
	if(k != n - 1){
		swap(v[0] , v[k]);
	}
	if(k == n - 1){
		swap(v[0] , v[n - 2]);
		swap(v[1] , v[n - 4]);
	}
	for(ll i = 0 ; i < lm ; i++){
		cout<<v[i]<<' '<<v[o ^ i]<<'\n';
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