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

const ll maxn = 100 + 17 , md = 1e9 + 7 , inf = 2e8;

int n;
bitset<maxn> a[maxn][maxn];
int c[maxn][maxn] , par[maxn] , dis[maxn][maxn];
vector<int> v[maxn][maxn] , bfs , adj[maxn];
string s;

void BFS(int r){
	bfs.clear();
	bfs.push_back(r);
	int x = 0;
	while(x < sze(bfs)){
		int u = bfs[x++];
		for(auto i : adj[u]){
			if(dis[r][i] > dis[r][u] + 1){
				dis[r][i] = dis[r][u] + 1;
				bfs.push_back(i);
			}
		}
	}
	return;
}

bool check(int r){
	memset(par , -1 , sizeof(par));
	bfs.clear();
	for(auto j : v[0][r]){
		bfs.push_back(j);
		par[j] = 0;
	}
	int x = 0;
	while(x < sze(bfs)){
		int u = bfs[x++];
		for(auto i : v[u][c[u][par[u]]]){
			if(i == par[u]) continue;
			if(par[i] != -1){
				return false;
			}
			par[i] = u;
			bfs.push_back(i);
		}
	}
	if(x < n - 1) return false;
	for(int i = 0 ; i < n ; i++){
		adj[i].clear();
	}
	for(int i = 1 ; i < n ; i++){
		adj[i].push_back(par[i]); adj[par[i]].push_back(i);
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			dis[i][j] = dis[j][i] = inf;
		}
	}
	for(int i = 0 ; i < n ; i++){
		BFS(i);
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				if((dis[i][j] == dis[i][k]) ^ (a[i][j][k])) return false;
			}
		}
	}
	return true;
}

void solve(){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			v[i][j].clear(); v[i][j].shrink_to_fit();
		}
	}
	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = 0 ; j < n - i - 1 ; j++){
			cin>>s;
			for(int k = 0 ; k < n ; k++){
				a[k][i][i + j + 1] = a[k][i + j + 1][i] = s[k] ^ '0';
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int h = j;
			for(int k = 0 ; k < n ; k++){
				if(a[i][j][k]){
					h = min(h , k);
					break;
				}
			}
			c[i][j] = h;
			v[i][h].push_back(j);
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				if((c[i][j] == c[i][k]) ^ (a[i][j][k])){
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	for(int i = 1 ; i < n ; i++){
		if(v[0][i].empty()) continue;
		if(check(i)){
			cout<<"YES\n";
			for(int j = 1 ; j < n ; j++){
				cout<<j + 1<<' '<<par[j] + 1<<'\n';
			}
			return;
		}
	}
	cout<<"No\n";
	return;
}

/*
1
2
00
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(int i = 0 ; i < maxn ; i++){
		for(int j = 0 ; j < maxn ; j++){
			a[i][j][j] = true;
		}
	}
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
} // maxn