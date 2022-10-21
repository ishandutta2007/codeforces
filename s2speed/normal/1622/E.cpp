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

const ll maxn = 1e4 + 16 , md = 998244353 , inf = 2e16;

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

ll n , m;
bitset<maxn> a[10];
ll ans[maxn];
ll x[maxn] , z[maxn];
vector<ll> v[22];
string s;

ll cal(ll mask){
	ll res = 0;
	for(ll i = 0 ; i < m ; i++) z[i] = 0;
	for(ll j = 0 ; j <= 20 ; j++) v[j].clear();
	for(ll j = 0 ; j < n ; j++){
		ll h;
		if(mask & (1 << j)){
			h = -1;
			res += x[j];
		} else {
			h = 1;
			res -= x[j];
		}
		for(ll i = 0 ; i < m ; i++){
			z[i] += h * a[j][i];
		}
	}
	for(ll i = 0 ; i < m ; i++){
		v[z[i] + n].push_back(i);
	}
	ll y = n << 1;
	for(ll i = m ; i > 0 ; i--){
		while(v[y].empty()) y--;
		ll t = y - n;
		res += t * i;
		ans[v[y].back()] = i;
		v[y].pop_back();
	}
	return res;
}

void solve(){
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = s[j] ^ '0';
		}
	}
	ll lm = (1 << n) , res = -inf , ind = -1;
	for(ll mask = 0 ; mask < lm ; mask++){
		ll h = cal(mask);
		if(h > res){
			res = h;
			ind = mask;
		}
	}
	cal(ind);
	for(ll i = 0 ; i < m ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return;
}

/*
1
4 4
6 2 0 10
1001
0010
0110
0101
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}