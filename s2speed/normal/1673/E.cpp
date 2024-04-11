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

const ll maxn = 1.1e6 + 17 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll lcm(ll a , ll b){
	return 1ll * a * b / gcd(a , b);
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

bool chs(ll n , ll k){
	if(k > n || k < 0) return false;
	bool res = (k & (n - k));
	return 1 - res;
}

bitset<maxn> ans;
ll b[maxn];
bool c[30][3];
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll lm = 1 << 20;
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	for(ll i = 0 ; i < 30 ; i++){
		ll nc = n - 1 - i;
		for(ll j = k ; j <= nc ; j++){
			c[i][0] ^= chs(nc , j);
		}
		c[i][1] = c[i][0] ^ chs(nc , k - 1);
		c[i][2] = c[i][1] ^ chs(nc , k - 2);
	}
	for(ll i = 0 ; i < n ; i++){
		ll cnt = b[i];
		for(ll j = i ; cnt < lm ; j++){
			ll nc = (j - i) + (i > 0) + (j < n - 1) , kc = (i > 0) + (j < n - 1);
			if(c[nc][kc]) ans[cnt].flip();
			if(j == n - 1) break;
			if(b[j + 1] >= 20) break;
			cnt *= (1ll << b[j + 1]);
		}
	}
	bool f = false;
	for(ll i = lm - 1 ; ~i ; i--){
		f |= ans[i];
		if(f) s += ans[i] + '0';
	}
	if(s.empty()) s = '0';
	cout<<s<<'\n';
	return 0;
}