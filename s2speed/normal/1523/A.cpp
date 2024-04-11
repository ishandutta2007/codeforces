#include<bits/stdc++.h>
 
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
typedef pair<pll , ll> plll;
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

bitset<maxn> a , b;

void solve(){
	ll n , m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(ll i = 0 ; i < n ; i++){
		a[i] = (s[i] == '1');
	}
	for(ll j = 0 ; j < m ; j++){
		b = a;
		for(ll i = 0 ; i < n ; i++){
			if(a[i]) continue;
			bool h = false;
			if(i > 0) h ^= a[i - 1];
			if(i < n - 1) h ^= a[i + 1];
			b[i] = h;
		}
		if(a == b) break;
		a = b;
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<a[i];
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