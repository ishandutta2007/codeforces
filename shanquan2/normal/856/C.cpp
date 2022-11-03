#include<bits/stdc++.h>
#define M 998244353
using namespace std;

int n,a[2005],b[2005],n1,n2,f[2][2005][11],g[2][2005][11],h[11];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		n1=n2=0;
		for(int i=0;i<n;i++){
			int x;scanf("%d",&x);
			int c=0,y=x;for(;y;y/=10)c++;
			if(c&1)a[n1++]=x%11;else b[n2++]=x%11;
		}
		memset(f,0,sizeof(f));f[0][0][0]=1;
		for(int i=0;i<n1;i++){
			int p=i&1,x=p^1;
			memset(f[x],0,sizeof(f[x]));
			for(int j=0;j<n1;j++)for(int k=0;k<11;k++)if(f[p][j][k]){
				(f[x][j][(k+11-a[i])%11]+=f[p][j][k])%=M;
				(f[x][j+1][(k+a[i])%11]+=f[p][j][k])%=M;
			}
		}
		int c0=n1+2>>1,c1=n1+1>>1;
		memset(g,0,sizeof(g));g[0][0][0]=1;
		for(int i=0;i<n2;i++){
			int p=i&1,x=p^1;
			memset(g[x],0,sizeof(g[x]));
			for(int j=0;j<n2;j++)for(int k=0;k<11;k++)if(g[p][j][k]){
				(g[x][j][(k+11-b[i])%11]+=1ll*g[p][j][k]*(c1+i-j)%M)%=M;
				(g[x][j+1][(k+b[i])%11]+=1ll*g[p][j][k]*(c0+j)%M)%=M;
			}
		}
		memset(h,0,sizeof(h));
		for(int i=0;i<=n2;i++)for(int j=0;j<11;j++)h[j]=(h[j]+g[n2&1][i][j])%M;
		int ans=0;
		for(int i=0;i<11;i++)ans=(ans+1ll*f[n1&1][n1>>1][i]*h[(11-i)%11])%M;
		for(int i=0;i<n1+1>>1;i++)ans=1ll*ans*(i+1)%M;
		for(int i=0;i<n1>>1;i++)ans=1ll*ans*(i+1)%M;
		printf("%d\n",ans);
	}
	return 0;
}