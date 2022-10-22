#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define size(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e18;
 
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

bitset<maxn> z;
ll dp[maxn] , a[maxn] , b[maxn];
vector<ll> adj[maxn];

void DFS(ll r , ll par){
	ll cnt = 0;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
		cnt += z[i];
		z[r] = z[r] ^ z[i];
		dp[r] += dp[i];
	}
	bool tr = z[r];
	ll pr = -1;
	for(auto i : adj[r]){
		if(i == par) continue;
		if(z[i]){
			if(!tr){
				a[i] = r;
				a[r] = i;
				b[a[i]] = i;
				b[a[r]] = r;
				tr = true;
			} else {
				if(pr == -1){
					pr = i;
				} else {
					a[pr] = i;
					a[i] = pr;
					b[a[pr]] = pr;
					b[a[i]] = i;
					pr = -1;
				}
			}
		}
	}
	if(z[r]){
		for(auto i : adj[r]){
			if(i == par) continue;
			if(z[i]){
				a[b[i]] = r;
				a[r] = i;
				b[r] = b[i];
				b[a[r]] = r;
				z[r] = false;
				break;
			}
		}
	}
	dp[r] += (cnt << 1);
	return;
}

/*
4
1 2 2 3 2 4
*/

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	z.set();
	memset(dp , 0 , sizeof(dp));
	memset(a , -1 , sizeof(a));
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	if(z[0]){
		dp[0] += 2;
		ll i = adj[0][0];
		a[b[i]] = 0;
		a[0] = i;
	}
	cout<<dp[0]<<'\n';
	for(ll i = 0 ; i < n ; i++){
		cout<<a[i] + 1<<' ';
	}
	cout<<'\n';
	return 0;
}