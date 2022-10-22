#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll { ll x , y , z; };
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

set<pll> s;
ll a[maxn];

void solve(){
	ll n , m , x;
	cin>>n>>m>>x;
	s.clear();
	for(ll i = 1 ; i <= m ; i++){
		s.insert({0 , i});
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		pll p = *s.begin(); s.erase(s.begin());
		p.first += h; a[i] = p.second;
		s.insert(p);
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < n ; i++){
		cout<<a[i]<<' ';
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