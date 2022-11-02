#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 505;

int n,m,k,f[N][N][11],w[N][N],v[N][N];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		for(int i=1;i <= n;i++) for(int j=1;j <= m;j++) printf("%d%c",-1,j == m ? '\n' : ' ');
		return 0;
	}
	k >>= 1;
	for(int i=1;i <= n;i++) for(int j=1;j < m;j++) scanf("%d",&w[i][j]);
	for(int i=1;i < n;i++) for(int j=1;j <= m;j++) scanf("%d",&v[i][j]);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i <= n;i++) for(int j=1;j <= m;j++) f[i][j][0] = 0;
	for(int t=1;t <= k;t++) {
		for(int i=1;i <= n;i++) for(int j=1;j <= m;j++)
			f[i][j][t] = min(f[i-1][j][t-1]+v[i-1][j],f[i+1][j][t-1]+v[i][j]),
			f[i][j][t] = min(f[i][j][t],min(f[i][j-1][t-1]+w[i][j-1],f[i][j+1][t-1]+w[i][j]));
	}
	for(int i=1;i <= n;i++) for(int j=1;j <= m;j++) printf("%d%c",f[i][j][k]<<1,j == m ? '\n' : ' ');
}