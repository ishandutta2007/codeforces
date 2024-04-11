#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
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

ll a[maxn][6];

void solve(){
	ll n , q;
	string s;
	cin>>n>>q>>s;
	// abc
	a[0][0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		a[i][0] = a[i - 1][0];
		if(i % 3 == 0){
			a[i][0] += (s[i - 1] != 'a');
		}
		if(i % 3 == 1){
			a[i][0] += (s[i - 1] != 'b');
		}
		if(i % 3 == 2){
			a[i][0] += (s[i - 1] != 'c');
		}
	}
	// acb
	a[0][1] = 0;
	for(ll i = 1 ; i <= n ; i++){
		a[i][1] = a[i - 1][1];
		if(i % 3 == 0){
			a[i][1] += (s[i - 1] != 'a');
		}
		if(i % 3 == 1){
			a[i][1] += (s[i - 1] != 'c');
		}
		if(i % 3 == 2){
			a[i][1] += (s[i - 1] != 'b');
		}
	}
	// bac
	a[0][2] = 0;
	for(ll i = 1 ; i <= n ; i++){
		a[i][2] = a[i - 1][2];
		if(i % 3 == 0){
			a[i][2] += (s[i - 1] != 'b');
		}
		if(i % 3 == 1){
			a[i][2] += (s[i - 1] != 'a');
		}
		if(i % 3 == 2){
			a[i][2] += (s[i - 1] != 'c');
		}
	}
	// bca
	a[0][3] = 0;
	for(ll i = 1 ; i <= n ; i++){
		a[i][3] = a[i - 1][3];
		if(i % 3 == 0){
			a[i][3] += (s[i - 1] != 'b');
		}
		if(i % 3 == 1){
			a[i][3] += (s[i - 1] != 'c');
		}
		if(i % 3 == 2){
			a[i][3] += (s[i - 1] != 'a');
		}
	}
	// cab
	a[0][4] = 0;
	for(ll i = 1 ; i <= n ; i++){
		a[i][4] = a[i - 1][4];
		if(i % 3 == 0){
			a[i][4] += (s[i - 1] != 'c');
		}
		if(i % 3 == 1){
			a[i][4] += (s[i - 1] != 'a');
		}
		if(i % 3 == 2){
			a[i][4] += (s[i - 1] != 'b');
		}
	}
	// cba
	a[0][5] = 0;
	for(ll i = 1 ; i <= n ; i++){
		a[i][5] = a[i - 1][5];
		if(i % 3 == 0){
			a[i][5] += (s[i - 1] != 'c');
		}
		if(i % 3 == 1){
			a[i][5] += (s[i - 1] != 'b');
		}
		if(i % 3 == 2){
			a[i][5] += (s[i - 1] != 'a');
		}
	}
	for(ll e = 0 ; e < q ; e++){
		ll l , r , ans = inf;
		cin>>l>>r;
		for(ll j = 0 ; j < 6 ; j++){
			ans = min(ans , a[r][j] - a[l - 1][j]);
		}
		cout<<ans<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();
	return 0;
}