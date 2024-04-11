//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 320;
vector<int> al[Maxn];
vector<int> leaf;
vector<int> ans;
vector<int> tmp;
int mat[Maxn][Maxn];
bool dfs(int v,int p,int dest){
//	cerr << v << " : )  " << dest << endl;
	if(v == dest){
		if(!dest)
			ans.push_back(v);
		return 1;
	}
	for(int i = 0; i < al[v].size();i++){
		int u = al[v][i];
		if(u == p)
			continue;
		if(dfs(u,v,dest)){
			ans.push_back(v);
			mat[u][v]--;
			mat[v][u]--;
			return 1;
		}
	}
	return 0;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1;i++){
		int u,v;
		cin >> u >> v;
		al[--u].push_back(--v);
		al[v].push_back(u);
		mat[v][u] = 2;
		mat[u][v] = 2;
	}
	int now = 0;
	while(cin >> now){
		if(now == -1)
			break;
		leaf.push_back(--now);
	}
	leaf.push_back(0);
	for(int i = 0;i < leaf.size();i++){
		if(i)
			dfs(leaf[i],-1,leaf[i-1]);
		else
			dfs(leaf[0],-2,leaf[leaf.size()-1]);
	}
	for(int i = 0; i < n;i++)
		for(int j = 0; j < n;j++)
			if(mat[i][j]){
	//			cerr << i << " " << j << endl;
				cout << -1 << endl;
				return 0;
			}
	for(int i = 0; i < 2 * n - 1;i++){
		cout << ans[i]+1 << " ";
	}
	cout << endl;
	return 0;
}