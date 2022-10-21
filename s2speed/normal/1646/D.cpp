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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll bp(ll p){
	ll o = 1 , cnt = 0;
	for(int i = 0 ; i < 63 ; i++){
		if(o & p) cnt++;
		o <<= 1;
	}
	return cnt;
}

vector<ll> adj[maxn];
ll w[maxn] , dp[maxn][2] , pd[maxn][2];
bitset<maxn> mark;

void dDFS(ll r , ll par){
	dp[r][0] = 0; dp[r][1] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r);
		dp[r][1] += dp[i][0];
		dp[r][0] += max(dp[i][0] , dp[i][1]);
	}
	return;
}

void pDFS(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
		ll h = 0;
		if(dp[i][0] >= dp[i][1]){
			h = max(h , pd[i][0] + 1);
		}
		if(dp[i][1] >= dp[i][0]){
			h = max(h , pd[i][1]);
		}
		pd[r][0] += h;
		pd[r][1] += pd[i][0];
	}
	return;
}

void mDFS(ll r , ll par , bool j){
	if(!j || dp[r][0] > dp[r][1]){
		mark[r] = false;
		for(auto i : adj[r]){
			if(i == par) continue;
			mDFS(i , r , true);
		}
		return;
	}
	if(dp[r][1] > dp[r][0]){
		mark[r] = true;
		for(auto i : adj[r]){
			if(i == par) continue;
			mDFS(i , r , false);
		}
		return;
	}
	if(pd[r][0] >= pd[r][1]){
		mark[r] = false;
		for(auto i : adj[r]){
			if(i == par) continue;
			mDFS(i , r , true);
		}
		return;
	}
	mark[r] = true;
	for(auto i : adj[r]){
		if(i == par) continue;
		mDFS(i , r , false);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(pd , 0 , sizeof(pd));
	ll n;
	cin>>n;
	if(n == 2){
		cout<<"2 2\n1 1\n";
		return 0;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	dDFS(0 , -1);
	pDFS(0 , -1);
//	for(ll i = 0 ; i < n ; i++){
//		cout<<dp[i][0]<<' '<<dp[i][1]<<"  "<<pd[i][0]<<' '<<pd[i][1]<<'\n';
//	}
	mDFS(0 , -1 , 1);
	cout<<max(dp[0][1] , dp[0][0])<<' ';
	ll sum = 0;
	for(ll i = 0 ; i < n ; i++){
		w[i] = (mark[i] ? sze(adj[i]) : 1);
		sum += w[i];
	}
	cout<<sum<<'\n';
	for(ll i = 0 ; i < n ; i++){
		cout<<w[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

/*
4
1 2 2 3 3 4
*/