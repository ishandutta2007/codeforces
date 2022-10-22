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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e17;

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

int n , k;
vector<int> adj[maxn] , jda[maxn] , ft , v[maxn] , cdj[maxn];
int jad[maxn][20] , dis[maxn] , dep = 0 , c[maxn] , o = 0 , w[maxn] , dp[maxn];
bitset<maxn> leaf , mark;

void jDFS(int r , int par){
	dis[r] = dep++;
	jad[r][0] = par;
	for(int j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	leaf[r] = adj[r].empty();
	for(auto i : adj[r]){
		jDFS(i , r);
	}
	dep--;
	ft.push_back(r);
	return;
}

int find_jad(int v){
	for(int j = 0 ; j < 20 ; j++){
		if(k & (1 << j)) v = jad[v][j];
	}
	return v;
}

void cDFS(int r){
	c[r] = o;
	v[o].push_back(r);
	for(auto i : jda[r]){
		if(c[i] != -1) continue;
		cDFS(i);
	}
	return;
}

void dDFS(int r){
	mark[r] = true;
	for(auto i : cdj[r]){
		if(mark[i]) continue;
		dDFS(i);
		dp[r] = max(dp[r] , dp[i]);
	}
	dp[r] += w[r];
	return;
}

/*
9 2
1 1 2 3 2 3 6 7
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	memset(c , -1 , sizeof(c));
	memset(w , 0 , sizeof(w));
	memset(dp , 0 , sizeof(dp));
	cin>>n>>k;
	for(int i = 1 ; i < n ; i++){
		int h;
		cin>>h; h--;
		adj[h].push_back(i); jda[i].push_back(h);
	}
	jDFS(0 , -1);
	for(int i = 0 ; i < n ; i++){
		if(!leaf[i]) continue;
		int h = (dis[i] <= k ? 0 : find_jad(i));
		adj[i].push_back(h); jda[h].push_back(i);
	}
	reverse(all(ft));
	for(int j = 0 ; j < n ; j++){
		int i = ft[j];
		if(c[i] != -1) continue;
		cDFS(i);
		o++;
	}
	for(int j = 0 ; j < o ; j++){
		for(auto i : v[j]){
			w[j] += leaf[i];
			for(auto u : adj[i]){
				int h = c[u];
				if(h != j){
					cdj[j].push_back(h);
				}
			}
		}
	}
	dDFS(0);
//	for(int i = 0 ; i < n ; i++){
//		cout<<c[i]<<' ';
//	}
//	cout<<'\n';
	cout<<dp[0]<<'\n';
	return 0;
}