#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> vis;
vector<string> v;

int dx[8] = {0,0,1,-1,-1,-1,1,1}, dy[8] = {1,-1,0,0,-1,1,-1,1};

int dfs(int x, int y){
	if(x < 0 || x >= v.size() || y < 0 || y >= v[0].size())return 0;
	if(vis[x][y] || v[x][y] == '.')return 0;
	vis[x][y] = 1;
	int ans = 1;
	for(int i = 0; i < 8; ++i){
		ans+=dfs(x+dx[i],y+dy[i]);
	}
	return ans;
}

void solve(){
	int n, m; cin >> n >> m;
	vis.clear();
	vis.resize(n,vector<int>(m,0));
	v.clear();
	v.resize(n);
	for(auto &x : v) cin >> x;
	int am = 0, am2 = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(v[i][j] == '.')continue;
			int z = dfs(i,j);
			am2+=z;
			if(z > 3){
				cout << "NO\n";
				return;
			}
			if(j && j < m-1)if(v[i][j-1] == v[i][j] && v[i][j] == v[i][j+1]){
				cout << "NO\n";
				return;
			}
			if(i && i < n-1)if(v[i-1][j] == v[i][j] && v[i+1][j] == v[i][j]){
				cout << "NO\n";
				return;
			}
			if(i && j)if(v[i-1][j] == v[i][j] && v[i][j-1] == v[i][j]){
				am++;
			}
			if(i < n-1 && j)if(v[i+1][j] == v[i][j] && v[i][j-1] == v[i][j]){
				am++;
			}
			if(i && j < m-1)if(v[i-1][j] == v[i][j] && v[i][j+1] == v[i][j]){
				am++;
			}
			if(i < n-1 && j < m-1)if(v[i+1][j] == v[i][j] && v[i][j+1] == v[i][j]){
				am++;
			}
		}
	}
	if(am*3 == am2){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";

	}
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}