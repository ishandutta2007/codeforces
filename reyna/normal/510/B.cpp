//In the name of God
#include <iostream>
#include <cmath>
using namespace std;
const int Maxn = 55;
string mat[Maxn];
bool vis[Maxn][Maxn];
int com[Maxn][Maxn];
int sub[Maxn * Maxn];
int edge[Maxn * Maxn];
int n,m;
int cnt;
void dfs(int i,int j){
	if(vis[i][j])
		return;
	vis[i][j] = 1;
	com[i][j] = cnt;
	sub[cnt]++;
	for(int r = -1;r < 2;r++){
		for(int l = -1; l < 2;l++){
			if(abs(l + r) == 1 && i + r != -1 && i + r != n && j + l != -1 && j + l != m && mat[i+r][j+l] == mat[i][j]){
				dfs(r+i,l+j);
			}
		}
	}
	return;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n;i++)
		cin >> mat[i];
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
			if(!vis[i][j])
				dfs(i,j),cnt++;
		}
	}
	for(int i = 0; i < n;i++)
		for(int j = 0;j < m;j++)
			for(int r = -1;r < 2;r++){
				for(int l = -1; l < 2;l++){
					if(abs(l + r) == 1 && i + r != -1 && i + r != n && j + l != -1 && j + l != m && mat[i+r][j+l] == mat[i][j]){
						edge[com[i][j]]++;
					}
				}
			}
	for(int i = 0; i < cnt;i++){
		if(edge[i]/2 >= sub[i]){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}