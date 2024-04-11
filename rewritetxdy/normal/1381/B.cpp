#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2020;

int t,n,c[N<<1],pre[N<<1],f[N][N][2];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= (n << 1);i++)
			scanf("%d",&c[i]) , pre[i] = max(c[i],pre[i-1]);
		f[1][0][0] = f[0][1][1] = 1;
		
		for(int i=0;i <= n;i++)
			for(int j=0;j <= n;j++){
				if(i+j < 1 || i+j >= 2*n) continue;
				
				int x = i+j+1;
				
				f[i+1][j][0] |= f[i][j][0];
				f[i][j+1][1] |= f[i][j][1];
				
				if(c[x] > pre[x-1]){
					f[i+1][j][0] |= f[i][j][1];
					f[i][j+1][1] |= f[i][j][0];
				}
			}
		if(f[n][n][0] || f[n][n][1])
			puts("YES");
		else puts("NO");
		for(int i=0;i <= n+1;i++)
			for(int j=0;j <= n+1;j++)
				f[i][j][0] = f[i][j][1] = 0;
		for(int i=1;i <= n*2;i++) pre[i] = 0;
	}
}