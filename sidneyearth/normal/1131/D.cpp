#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 2 * 1010;
char s[maxn][maxn];
int dp[maxn], f[maxn];
vector<int> G[maxn];
int Find(int u){ return u == f[u] ? u : f[u] = Find(f[u]); }
bool DFS(int u){
	if(dp[u] == -2) return false;
	else if(dp[u] != -1) return true;
	else{
		dp[u] = -2;
		int rnt = 1;
		for(auto v : G[u]){
			if(!DFS(v)) return false;
			rnt = max(rnt, dp[v] + 1);
		}
		dp[u] = rnt;
		return true;
	}
}
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for(int i = 1; i <= n + m; i++) f[i] = i, dp[i] = -1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '=') f[Find(n + j)] = Find(i);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '<') G[Find(n + j)].push_back(Find(i));
			else if(s[i][j] == '>') G[Find(i)].push_back(Find(n + j));
	int ans = true;
	for(int i = 1; i <= n + m; i++)
		if(Find(i) == i && !DFS(i)){
			ans = false;
			break;
		}
	if(ans){
		printf("Yes\n");
		for(int i = 1; i <= n + m; i++)
			printf("%d%c", dp[Find(i)], " \n"[i==n||i==n+m]);
	}
	else
		printf("No\n");
	return 0;
}