#include<bits/stdc++.h>
const int N=4003,M=998244353;
using namespace std;
int n,m,k,f[3][N],g[3][N],
p[N][N],cx[N],cy[N];
int cn,cm,r0,c0,r1,c1,ans,vx[N],vy[N];
int main(){
	scanf("%d%d%d",&cn,&cm,&k);
	for(;k--;){
		scanf("%d%d%d%d",&r0,&c0,&r1,&c1);
		cx[r0]++,cy[c0]++;
		if(r0^r1)cx[r1]++;else cy[c1]++;
	}
	for(int i=1;i<=cn;i++){
		if(cx[i]>1)return puts("0"),0;
		if(!cx[i])vx[++n]=cx[i+1];
	}
	for(int i=1;i<=cm;i++){
		if(cy[i]>1)return puts("0"),0;
		if(!cy[i])vy[++m]=cy[i+1];
	}
	for(int i=0;i<=max(n,m);i++){
		p[i][i]=1;
		for(int j=i;j;j--)
		p[i][j-1]=1ll*p[i][j]*j%M;
	}
	f[0][0]=g[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j*2<=n&&j<=m;j++){
		f[i%3][j]=f[(i+2)%3][j];
		if(i>1&&vx[i-1]==0&&j)
		f[i%3][j]=(f[i%3][j]+f[(i+1)%3][j-1])%M;
	}
	for(int i=1;i<=m;i++)
	for(int j=0;j*2<=m&&j<=n;j++){
		g[i%3][j]=g[(i+2)%3][j];
		if(i>1&&vy[i-1]==0&&j)
		g[i%3][j]=(g[i%3][j]+g[(i+1)%3][j-1])%M;
	}
	for(int i=0;i*2<=n;i++)
	for(int j=0;j<=n-2*i&&i<=m-2*j;j++)
	ans=(ans+1ll*f[n%3][i]*g[m%3][j]%M*p[m-2*j][m-2*j-i]%M*p[n-2*i][n-2*i-j])%M;
	printf("%d",ans);
}