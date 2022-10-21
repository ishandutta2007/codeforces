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

const ll maxn = 2e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

char c[maxn][maxn];
ll f[maxn * maxn] , adj[maxn * maxn] , mark[maxn * maxn];
vector<ll> v;

void solve(){
	ll n , m;
	cin>>n>>m;
	ll lm = n * m;
	for(ll i = 0 ; i < lm ; i++) f[i] = -1;
	for(ll i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			c[i][j] = s[j];
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ll v = i * m + j;
			if(c[i][j] == 'D'){
				adj[v] = v + m;
				if(i == n - 1) adj[v] = v;
			}
			if(c[i][j] == 'U'){
				adj[v] = v - m;
				if(i == 0) adj[v] = v;
			}
			if(c[i][j] == 'L'){
				adj[v] = v - 1;
				if(j == 0) adj[v] = v;
			}
			if(c[i][j] == 'R'){
				adj[v] = v + 1;
				if(j == m - 1) adj[v] = v;
			}
		}
	}
	for(ll i = 0 ; i < lm ; i++){
		if(f[i] != -1) continue;
		ll h = i;
		while(true){
			if(mark[h] != -1){
				ll d = sze(v) - mark[h];
				while(v.back() != h){
					f[v.back()] = d;
					mark[v.back()] = -1;
					v.pop_back();
				}
				f[v.back()] = d;
				mark[v.back()] = -1;
				v.pop_back();
			}
			if(f[h] != -1){
				ll cur = f[h];
				while(!v.empty()){
					f[v.back()] = ++cur;
					mark[v.back()] = -1;
					v.pop_back();
				}
				break;
			}
			mark[h] = sze(v);
			v.push_back(h);
			h = adj[h];
		}
	}
	ll mx = -1 , ind = -1;
	for(ll i = 0 ; i < lm ; i++){
		if(f[i] > mx){
			mx = f[i]; ind = i;
		}
	}
	cout<<ind / m + 1<<' '<<ind % m + 1<<' '<<mx<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(mark , -1 , sizeof(mark));
	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}