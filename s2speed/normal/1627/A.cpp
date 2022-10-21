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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> a[maxn];

void solve(){
	ll n , m , r , c;
	bool f = false;
	cin>>n>>m>>r>>c; r--; c--;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			char t;
			cin>>t;
			a[i][j] = (t == 'B');
			f |= a[i][j];
		}
	}
	if(!f){
		cout<<"-1\n";
		return;
	}
	if(a[r][c]){
		cout<<"0\n";
		return;
	}
	f = false;
	for(ll j = 0 ; j < m ; j++) f |= a[r][j];
	for(ll i = 0 ; i < n ; i++) f |= a[i][c];
	cout<<2 - f<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}