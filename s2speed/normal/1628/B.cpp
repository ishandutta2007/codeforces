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

bitset<27> a[27] , b[27][27];
vector<vector<ll>> v;

void solve(){
	v.clear();
	ll n;
	bool f = false;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		vector<ll> h;
		f |= (sze(s) == 1);
		if(sze(s) == 2){
			f |= (s[0] == s[1]);
		}
		if(sze(s) == 3){
			f |= (s[0] == s[2]);
		}
		for(ll i = 0 ; i < sze(s) ; i++){
			h.push_back(s[i] - 'a');
		}
		v.push_back(h);
	}
	if(f){
		cout<<"YES\n";
		return;
	}
	for(auto h : v){
		if(sze(h) == 2){
			a[h[0]][h[1]] = true;
			f |= a[h[1]][h[0]];
			for(ll j = 0 ; j < 26 ; j++) f |= b[h[1]][h[0]][j];
		}
		if(sze(h) == 3){
			b[h[0]][h[1]][h[2]] = true;
			f |= b[h[2]][h[1]][h[0]];
			f |= a[h[2]][h[1]];
		}
	}
	for(auto h : v){
		if(sze(h) == 2){
			a[h[0]][h[1]] = false;
		}
		if(sze(h) == 3){
			b[h[0]][h[1]][h[2]] = false;
		}
	}
	cout<<(f ? "YES" : "NO")<<'\n';
	return;
}

/*
1
3
ab
cd
cba
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}