#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1e9+7;
int n;
int org[233][233];
int a[233][233];
inline int pow(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
#define inv(x) pow(x,MOD-2)
int eli()
{
	int nn=n-1;
	for(int i=1;i<=nn;i++)
		for(int j=1;j<=nn;j++)
		{
			a[i][j]%=MOD;
			if(a[i][j]<0)a[i][j]+=MOD;
		}
	for(int i=1;i<=nn;i++)
	{
		int ok=0;
		for(int j=i;j<=nn;j++)if(a[j][i]!=0){ok=j;break;}
		if(!ok)return 0;
		for(int j=i;j<=nn;j++)swap(a[i][j],a[ok][j]);
		int invi=inv(a[i][i]);
		for(int j=i+1;j<=nn;j++)
		{
			int tmp=1ll*a[j][i]*invi%MOD;
			for(int k=i;k<=nn;k++)
			{
				a[j][k]-=1ll*a[i][k]*tmp%MOD;
				if(a[j][k]<0)a[j][k]+=MOD;
			}
		}
	}
	long long ret=1;
	for(int i=1;i<=nn;i++)ret*=a[i][i],ret%=MOD;
	return ret;
}
long long f[233],cha[233],tot[233],q[233],tmp[233];
#define rep(i) for(int i=1;i<=n;i++)
int main()
{
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		org[u][v]=org[v][u]=1;
	}
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(org[i][j])
					a[i][j]-=x,a[j][i]-=x,a[i][i]+=x,a[j][j]+=x;
				else
					a[i][j]-=1,a[j][i]-=1,a[i][i]+=1,a[j][j]+=1;
			}
		}
		//rep(i){rep(j)cout<<a[i][j]<<' ';cout<<endl;}cout<<endl;
		f[x]=eli();
		//cout<<f[x]<<endl;
		//rep(i){rep(j)cout<<a[i][j]<<' ';cout<<endl;}cout<<endl;
	}
	tot[1]=1;
	for(int i=1;i<=n;i++)
	{
		//tot*=(1,MOD-x[i])
		for(int p=1;p<=n+1;p++)tmp[p]=0;
		int ii=MOD-i;
		for(int p=1;p<=n+1;p++)
		{
			tmp[p+1]+=tot[p];
			tmp[p]+=tot[p]*ii;
			tot[p]=tmp[p]%MOD;
		}
		//for(int i=1;i<=n+1;i++)cout<<tot[i]<<' ';cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		long long qwq=1;
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
				qwq*=i>j?i-j:MOD+i-j,qwq%=MOD;
		}
		//cout<<qwq<<endl;
		qwq=inv(qwq);
		for(int j=1;j<=n+1;j++)tmp[j]=tot[j];
		int ii=MOD-i;
		for(int j=n;j>=1;j--)
		{
			q[j]=tmp[j+1];
			tmp[j]=(tmp[j]-ii*tmp[j+1])%MOD;
			if(tmp[j]<0)tmp[j]+=MOD;
		}
		for(int j=1;j<=n;j++)cha[j]+=q[j]*f[i]%MOD*qwq%MOD;
	}
	for(int i=1;i<=n;i++)printf("%lld ",cha[i]%MOD);
	return 0;
}