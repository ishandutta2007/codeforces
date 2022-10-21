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

const ll maxn = 5e3 + 17 , md = 1e9 + 7 , inf = 2e16;

string s;
bool a[maxn][maxn];

void solve(){
	ll n , m , cnt = 0;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = (s[j] ^ '0');
			cnt += a[i][j];
		}
	}
	if(cnt == 0){
		cout<<cnt<<'\n';
		return;
	}
	ll h = 3;
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 1 ; j < m ; j++){
			ll o = a[i][j] + a[i - 1][j] + a[i][j - 1];
			if(o > 0) h = min(h , o);
			o -= a[i][j - 1]; o += a[i - 1][j - 1];
			if(o > 0) h = min(h , o);
			o -= a[i - 1][j]; o += a[i][j - 1];
			if(o > 0) h = min(h , o);
			o -= a[i][j]; o += a[i - 1][j];
			if(o > 0) h = min(h , o);
		}
	}
	cout<<cnt - h + 1<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}