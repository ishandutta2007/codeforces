#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll n;
vector<ll> adj[maxn];
ll dp[maxn][2][2];

void DFS(ll r){
	for(auto i : adj[r]) DFS(i);
	ll h[2][2] , a , b;
	h[0][0] = h[1][1] = 0;
	h[0][1] = h[1][0] = 1;
	for(auto i : adj[r]){
		a = 1ll * (1 + dp[i][1][1]) * h[1][1] + 1ll * h[1][0] * dp[i][0][1]; a %= md;
		b = 1ll * h[1][1] * dp[i][1][0] + 1ll * h[1][0] * (1 + dp[i][0][0]); b %= md;
		h[1][1] = a; h[1][0] = b;
		a = 1ll * h[0][0] * (1 + dp[i][0][0]) + 1ll * h[0][1] * dp[i][1][0]; a %= md;
		b = 1ll * h[0][0] * dp[i][0][1] + 1ll * h[0][1] * (1 + dp[i][1][1]); b %= md;
		h[0][0] = a; h[0][1] = b;
	}
	dp[r][0][0] = h[0][0];
	dp[r][1][0] = h[1][0];
	dp[r][0][1] = h[0][1];
	dp[r][1][1] = h[1][1];
	reverse(all(adj[r]));
	h[0][0] = h[1][1] = 0;
	h[0][1] = h[1][0] = 1;
	for(auto i : adj[r]){
		a = 1ll * (1 + dp[i][1][1]) * h[1][1] + 1ll * h[1][0] * dp[i][0][1]; a %= md;
		b = 1ll * h[1][1] * dp[i][1][0] + 1ll * h[1][0] * (1 + dp[i][0][0]); b %= md;
		h[1][1] = a; h[1][0] = b;
		a = 1ll * h[0][0] * (1 + dp[i][0][0]) + 1ll * h[0][1] * dp[i][1][0]; a %= md;
		b = 1ll * h[0][0] * dp[i][0][1] + 1ll * h[0][1] * (1 + dp[i][1][1]); b %= md;
		h[0][0] = a; h[0][1] = b;
	}
	dp[r][0][0] += h[0][0]; if(dp[r][0][0] >= md) dp[r][0][0] -= md;
	dp[r][1][0] += h[1][0]; if(dp[r][1][0] >= md) dp[r][1][0] -= md;
	dp[r][0][1] += h[0][1]; if(dp[r][0][1] >= md) dp[r][0][1] -= md;
	dp[r][1][1] += h[1][1]; if(dp[r][1][1] >= md) dp[r][1][1] -= md;
	a = b = 1;
	for(auto i : adj[r]){
		a *= (1 + dp[i][1][1]); a %= md;
		b *= (1 + dp[i][0][0]); b %= md;
	}
	dp[r][0][1] -= a; if(dp[r][0][1] < 0) dp[r][0][1] += md;
	dp[r][1][0] -= b; if(dp[r][1][0] < 0) dp[r][1][0] += md;
	h[0][0] = h[1][1] = 0;
	h[0][1] = h[1][0] = 1;
	for(auto i : adj[r]){
		a = h[1][1] + 1ll * h[1][0] * dp[i][0][1]; a %= md;
		b = 1ll * h[1][1] * dp[i][1][0] + h[1][0]; b %= md;
		h[1][1] = a; h[1][0] = b;
		a = h[0][0] + 1ll * h[0][1] * dp[i][1][0]; a %= md;
		b = 1ll * h[0][0] * dp[i][0][1] + h[0][1]; b %= md;
		h[0][0] = a; h[0][1] = b;
	}
	dp[r][0][0] -= h[0][0]; if(dp[r][0][0] < 0) dp[r][0][0] += md;
	dp[r][1][1] -= h[1][1]; if(dp[r][1][1] < 0) dp[r][1][1] += md;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		adj[h].push_back(i);
	}
	DFS(0);
	ll ans = dp[0][0][0] + dp[0][0][1]; if(ans >= md) ans -= md;
	cout<<ans<<'\n';
	return 0;
}