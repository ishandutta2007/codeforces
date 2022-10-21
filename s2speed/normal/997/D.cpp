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

const ll maxn = 4e3 + 16 , maxk = 40 , md = 998244353 , inf = 2e16;

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

ll n , m , k;
ll chs[maxk << 1][maxk << 1];
ll dp[maxn][maxk] , pd[maxn][maxk] , f[maxn][maxk];
ll sum[maxk][2];
vector<ll> adj[maxn];

void dDFS(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r);
	}
	dp[r][0] = 1;
	for(ll j = 1 ; j <= k ; j++){
		ll h = 0;
		for(ll q = 0 ; q < j ; q++){
			for(auto i : adj[r]){
				if(i == par) continue;
				h += 1ll * dp[i][q] * dp[r][j - q - 1] % md;
			}
		}
		dp[r][j] = h % md;
	}
	return;
}

void pDFS(ll r , ll par){
	ll h[maxk];
	for(ll j = 0 ; j <= k ; j++){
		h[j] = pd[r][j];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		for(ll j = 0 ; j <= k ; j++){
			h[j] += dp[i][j];
		}
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		pd[i][0] = 1;
		for(ll j = 1 ; j <= k ; j++){
			ll o = 0;
			for(ll q = 0 ; q < j ; q++){
				o += 1ll * (h[q] - dp[i][q]) % md * pd[i][j - q - 1] % md;
			}
			o %= md; if(o < 0) o += md;
			pd[i][j] = o;
		}
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
	}
	return;
}

void fDFS(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		fDFS(i , r);
	}
	f[r][0] = 1;
	for(ll j = 1 ; j <= k ; j++){
		ll h = 0;
		for(ll q = 0 ; q < j ; q++){
			h += 1ll * pd[r][q] * f[r][j - q - 1] % md;
			for(auto i : adj[r]){
				if(i == par) continue;
				h += 1ll * dp[i][q] * f[r][j - q - 1] % md;
			}
		}
		f[r][j] = h % md;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(chs , 0 , sizeof(chs));
	chs[0][0] = 1;
	ll lm = maxk << 1;
	for(ll i = 1 ; i < lm ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j < lm ; j++){
			chs[i][j] = chs[i - 1][j] + chs[i - 1][j - 1];
			if(chs[i][j] >= md) chs[i][j] -= md;
		}
	}
	memset(dp , 0 , sizeof(dp));
	memset(pd , 0 , sizeof(pd));
	memset(f , 0 , sizeof(f));
	memset(sum , 0 , sizeof(sum));
	cin>>n>>m>>k;
	if(k & 1){
		cout<<"0\n";
		return 0;
	}
	k >>= 1;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	dDFS(0 , -1);
	pDFS(0 , -1);
	fDFS(0 , -1);
	for(ll j = 0 ; j <= k ; j++){
		for(ll i = 0 ; i < n ; i++){
			sum[j][0] += f[i][j];
		}
		sum[j][0] %= md;
	}
	memset(dp , 0 , sizeof(dp));
	memset(pd , 0 , sizeof(pd));
	memset(f , 0 , sizeof(f));
	for(ll i = 0 ; i < n ; i++) adj[i].clear();
	swap(n , m);
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	dDFS(0 , -1);
	pDFS(0 , -1);
	fDFS(0 , -1);
	for(ll j = 0 ; j <= k ; j++){
		for(ll i = 0 ; i < n ; i++){
			sum[j][1] += f[i][j];
		}
		sum[j][1] %= md;
	}
	ll ans = 0;
	for(ll j = 0 ; j <= k ; j++){
		ll h = 1ll * chs[k << 1][j << 1] * sum[j][0] % md * sum[k - j][1] % md;
		ans += h;
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}