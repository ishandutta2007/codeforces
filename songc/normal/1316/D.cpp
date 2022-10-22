#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
pii A[1010][1010];
char ans[1010][1010];

void dfs(int x, int y){
	if (A[x+1][y] == A[x][y] && !ans[x+1][y]){
		ans[x+1][y] = 'U';
		if (!ans[x][y]) ans[x][y] = 'D';
		dfs(x+1, y);
	}
	if (A[x-1][y] == A[x][y] && !ans[x-1][y]){
		ans[x-1][y] = 'D';
		if (!ans[x][y]) ans[x][y] = 'U';
		dfs(x-1, y);
	}
	if (A[x][y-1] == A[x][y] && !ans[x][y-1]){
		ans[x][y-1] = 'R';
		if (!ans[x][y]) ans[x][y] = 'L';
		dfs(x, y-1);
	}
	if (A[x][y+1] == A[x][y] && !ans[x][y+1]){
		ans[x][y+1] = 'L';
		if (!ans[x][y]) ans[x][y] = 'R';
		dfs(x, y+1);
	}
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) scanf("%d %d", &A[i][j].first, &A[i][j].second);
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++){
		if (ans[i][j]) continue;
		if (A[i][j] == pii(-1,-1)) dfs(i,j);
		if (A[i][j] == pii(i,j)){
			ans[i][j] = 'X';
			dfs(i, j);
		}
	}
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++){
		if (!ans[i][j]){
			puts("INVALID");
			return 0;
		}
	}
	puts("VALID");
	for (int i=1; i<=N; i++) puts(ans[i]+1);
	return 0;
}