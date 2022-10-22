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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 998244353 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

vector<ll> fib;
bitset<MAXN> dead;
vector<ll> adj[MAXN];
ll z[MAXN];
ll v = -1 , u = -1 , pv = -1 , pu = -1;

void DFS(ll r , ll par , ll k){
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		DFS(i , r , k);
		z[r] += z[i];
	}
	if(z[r] == fib[k - 1]){
		if(v == -1){
			v = r;
			pv = par;
		} else {
			u = r;
			pu = par;
		}
	}
	if(z[r] == fib[k - 2]){
		if(v == -1){
			v = r;
			pv = par;
		} else {
			u = r;
			pu = par;
		}
	}
	return;
}

bool fib_check(ll r , ll k){
	if(k <= 2) return true;
	DFS(r , -1 , k);
	ll o , h , ph , po;
	if(v == -1) return false;
	h = v; o = u; ph = pv; po = pu;
	bool revo;
	if(o != -1){
		revo = (z[o] == fib[k - 2]);
	}
	v = -1; u = -1; pv = -1; pu = -1;
	bool rev = (z[h] == fib[k - 2]);
	if(h != -1){
		bool res = true;
		dead[ph] = true;
		res &= fib_check(h , k - 1 - rev);
		dead[ph] = false;
		if(res){
			dead[h] = true;
			res &= fib_check(r , k - 2 + rev);
			dead[h] = false;
		}
		if(res) return true;
	}
	if(o != -1){
		bool res = true;
		dead[po] = true;
		res &= fib_check(o , k - 1 - revo);
		dead[po] = false;
		if(res){
			dead[o] = true;
			res &= fib_check(r , k - 2 + revo);
			dead[o] = false;
		}
		if(res) return true;
	}
	return false;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fib.push_back(1);
	ll p = 1 , c = 1;
	while(true){
		ll h = p + c;
		p = c;
		c = h;
		if(c > 2e5) break;
		fib.push_back(c);
	}
	ll n , k = -1 , fs = fib.size();
	cin>>n;
	for(ll i = 0 ; i < fs ; i++){
		if(fib[i] == n){
			k = i;
			break;
		}
	}
	if(k == -1){
		cout<<"NO\n";
		return 0;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	bool ans = fib_check(0 , k);
	cout<<(ans ? "YES\n" : "NO\n");
	return 0;
}

/*

*/