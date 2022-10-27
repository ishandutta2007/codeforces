#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 70 + 2;
int n,m,k,a[N][N],f[N][N][N][N],g[N][N], dp[N][N];
void upd(int &x,int y){
	x=max(x,y);
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)g[i][j]=-1e9;
	for(int i=1;i<=n;i++){
		for(int x=0;x<=m;x++) for(int y=0;y<=x;y++) for(int j=0;j<k;j++) f[i][x][y][j]=-1e9;
		f[i][0][0][0]=0;
		for(int x=0;x<m;x++){
			for(int y=0;y<=x;y++){
				for(int j=0;j<k;j++){
					upd(f[i][x+1][y][j],f[i][x][y][j]);
					upd(f[i][x+1][y+1][ (j+a[i][x+1])%k ], f[i][x][y][j] + a[i][x+1]);
				}
			}
		}
		for(int y=0;y<=m/2;y++) for(int j=0;j<k;j++) upd(g[i][j],f[i][m][y][j]);
	}
	
	for(int i=0;i<N;i++)for(int j=0;j<N;j++) dp[i][j]=-1e9;
	dp[0][0]=0;	
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			for(int c=0;c<k;c++){
				upd(dp[i+1][(j+c)%k], dp[i][j] + g[i+1][c]);
			}
		}
	}
	printf("%d\n", dp[n][0]);
}