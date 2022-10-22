#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 20 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll a[MAXN] , pr[MAXN] , sf[MAXN];
ll tr[40 * MAXN][2] , last = 0;

void insert(bitset<40> s){
	ll i = 39 , v = 0;
	while(i >= 0){
		if(tr[v][s[i]] == -1){
			tr[v][s[i]] = ++last;
		}
		v = tr[v][s[i]];
		i--;
	}
	return;
}

ll mxr(bitset<40> s){
	ll i = 39 , v = 0 , h = 1ll << 39 , res = 0;
	while(i >= 0){
		if(tr[v][!s[i]] != -1){
			res += h;
			v = tr[v][!s[i]];
		} else {
			v = tr[v][s[i]];
		}
		h >>= 1;
		i--;
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(tr , -1 , sizeof(tr));
	ll n;
	cin>>n; pr[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		pr[i] = pr[i - 1] ^ a[i];
	}
	sf[n + 1] = 0;
	for(ll i = n ; i > 0 ; i--){
		sf[i] = sf[i + 1] ^ a[i];
	}
	bitset<40> o;
	for(ll i = 0 ; i <= n ; i++){
		o = pr[i];
		insert(o);
	}
	ll ans = 0;
	for(ll i = 1 ; i <= n + 1 ; i++){
		o = sf[i];
		ll h = mxr(o);
		ans = max(ans , h);
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/