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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll a[maxn] , b[maxn] , A[maxn] , B[maxn] , dis[maxn] , dep = 0 , jad[maxn][20];
vector<ll> adj[maxn];

void DFS(ll r , ll par){
	dis[r] = dep++;
	if(r){
		A[r] = A[par] + a[r];
		B[r] = B[par] + b[r];
	}
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		DFS(i , r);
	}
	dep--;
	return;
}

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear();
		for(ll j = 0 ; j < 20 ; j++) jad[i][j] = -1;
	}
	for(ll i = 1 ; i < n ; i++){
		ll p;
		cin>>p>>a[i]>>b[i]; p--;
		adj[p].push_back(i);
	}
	DFS(0 , -1);
	for(ll i = 1 ; i < n ; i++){
		if(B[i] <= A[i]){
			cout<<dis[i]<<' ';
			continue;
		}
		ll v = i;
		for(ll j = 19 ; ~j ; j--){
			if(jad[v][j] == -1) continue;
			if(B[jad[v][j]] > A[i]){
				v = jad[v][j];
			}
		}
		cout<<dis[v] - 1<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}