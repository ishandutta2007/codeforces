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

ll a[maxn];
string s;
vector<ll> r , b;

void solve(){
	r.clear(); b.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	cin>>s;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == 'B'){
			b.push_back(a[i]);
		} else {
			r.push_back(a[i]);
		}
	}
	sort(all(b)); sort(all(r) , greater<ll>());
	ll bs = sze(b) , rs = sze(r);
	for(ll i = 0 ; i < bs ; i++){
		if(b[i] < i + 1){
			cout<<"NO\n";
			return;
		}
	}
	for(ll i = 0 ; i < rs ; i++){
		if(r[i] > n - i){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}