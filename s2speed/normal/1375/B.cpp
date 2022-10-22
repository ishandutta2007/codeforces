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

const ll maxn = 500 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn][maxn];

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
		}
	}
	if(a[0][0] > 2){
		cout<<"NO\n";
		return;
	}
	if(a[0][m - 1] > 2){
		cout<<"NO\n";
		return;
	}
	if(a[n - 1][0] > 2){
		cout<<"NO\n";
		return;
	}
	if(a[n - 1][m - 1] > 2){
		cout<<"NO\n";
		return;
	}
	a[0][0] = a[0][m - 1] = a[n - 1][0] = a[n - 1][m - 1] = 2;
	for(ll i = 1 ; i < n - 1 ; i++){
		if(a[i][0] > 3 || a[i][m - 1] > 3){
			cout<<"NO\n";
			return;
		}
		a[i][0] = a[i][m - 1] = 3;
	}
	for(ll j = 1 ; j < m - 1 ; j++){
		if(a[0][j] > 3 || a[n - 1][j] > 3){
			cout<<"NO\n";
			return;
		}
		a[0][j] = a[n - 1][j] = 3;
	}
	for(ll i = 1 ; i < n - 1 ; i++){
		for(ll j = 1 ; j < m - 1 ; j++){
			if(a[i][j] > 4){
				cout<<"NO\n";
				return;
			}
			a[i][j] = 4;
		}
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
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