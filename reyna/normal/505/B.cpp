//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 123;
int vis[Maxn][Maxn];
vector<int> al[Maxn][Maxn];
void dfs(int v,int c){
	if(vis[v][c])
		return;
	vis[v][c] = 1;
	for(int i = 0; i < al[c][v].size();i++){
		int u = al[c][v][i];
		dfs(u,c);
	}
	return;
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m;i++){
		int u,v,c;
		cin >> u >> v >> c;
		al[--c][--v].push_back(--u);
		al[c][u].push_back(v);
	}
	int q;
	cin >> q;
	for(int i = 0; i < q;i++){
		int u,v;
		cin >> u >> v;
		--u;
		for(int j = 0; j < m;j++)
			dfs(u,j);
		int ans = 0;
		--v;
		for(int j = 0; j < m;j++)
			ans += vis[v][j];
		for(int j = 0; j < n;j++)
			for(int k = 0; k < m;k++)
				vis[j][k] = 0;
		cout << ans << endl;
	}
	return 0;
}