#include<cstdio>
#define MN 50
#define MOD 1000000007
int c[MN+5],f[MN+5][MN+5][MN+5],C[MN+5][MN+5],F[MN+5][2],p[MN+5];
inline void rw(int&x,int y){if((x+=y)>=MOD)x-=MOD;}
int main()
{
	int n,m,i,j,k,l,x,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&c[i]);
	for(i=0;i<=n;++i)
	{
		for(C[i][0]=j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		for(j=0;j<=i;++j)rw(F[i][j&1],C[i][j]);
	}
	for(p[0]=i=1;i<=n;++i)p[i]=(p[i-1]+p[i-1])%MOD;
	f[0][0][0]=1;
	for(i=0;i<n;++i)for(j=0;j<=i;++j)for(k=0;k<=i;++k)if(f[i][j][k])
	{
		if(c[i+1]!=0)
			rw(f[i+1][j+1][k],1LL*f[i][j][k]*F[k][0]%MOD*p[i-k]%MOD),
			rw(f[i+1][j  ][k],1LL*f[i][j][k]*F[k][1]%MOD*p[i-k]%MOD);
		if(c[i+1]!=1)
			rw(f[i+1][j][k+1],1LL*f[i][j][k]*F[j][0]%MOD*p[i-j]%MOD),
			rw(f[i+1][j][k  ],1LL*f[i][j][k]*F[j][1]%MOD*p[i-j]%MOD);
	}
	for(i=0;i<=n;++i)for(j=0;j<=n;++j)if(((i+j)&1)==m)rw(ans,f[n][i][j]);
	printf("%d",ans);
}