#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long LL;
const int mod=1000000007;
LL n;
int A,B,C,c;
LL f[10],f1[10],mxt[10][10],mxt1[10][10];

LL getmi(LL a,LL x)
{
	LL rt=1;
	while(x)
	{
		if(x&1) rt=rt*a%mod;
		a=a*a%mod,x>>=1;
	}
	return rt;
}

LL solve(LL n,int p)
{
	while(n)
	{
		if(n&1)
		{
			memset(f1,0,sizeof(f1));
			rep(i,0,4) rep(j,0,4) f1[i]=(f1[i]+f[j]*mxt[i][j])%p;
			rep(i,0,4) f[i]=f1[i];
		}
		memset(mxt1,0,sizeof(mxt1));
		rep(i,0,4) rep(j,0,4) rep(k,0,4) mxt1[i][j]=(mxt1[i][j]+mxt[i][k]*mxt[k][j])%p;
		rep(i,0,4) rep(j,0,4) mxt[i][j]=mxt1[i][j];
		n>>=1;
	}
	return f[2];
}

int main()
{
	scanf("%lld%d%d%d%d",&n,&A,&B,&C,&c);
	f[0]=0,f[1]=0,f[2]=0,f[3]=4,f[4]=-1;
	mxt[0][1]=1;
	mxt[1][2]=1;
	mxt[2][0]=mxt[2][1]=mxt[2][2]=1,mxt[2][3]=2,mxt[2][4]=6;
	mxt[3][3]=1,mxt[3][4]=-1;
	mxt[4][4]=1;
	LL ans=getmi(c,solve(n-3,mod-1));

	memset(f,0,sizeof(f));
	memset(mxt,0,sizeof(mxt));
	f[0]=1;
	mxt[0][1]=1;
	mxt[1][2]=1;
	mxt[2][0]=mxt[2][1]=mxt[2][2]=1;
	ans=ans*getmi(A,solve(n-3,mod-1))%mod;
	
	memset(f,0,sizeof(f));
	memset(mxt,0,sizeof(mxt));
	f[1]=1;
	mxt[0][1]=1;
	mxt[1][2]=1;
	mxt[2][0]=mxt[2][1]=mxt[2][2]=1;
	ans=ans*getmi(B,solve(n-3,mod-1))%mod;

	memset(f,0,sizeof(f));
	memset(mxt,0,sizeof(mxt));
	f[2]=1;
	mxt[0][1]=1;
	mxt[1][2]=1;
	mxt[2][0]=mxt[2][1]=mxt[2][2]=1;
	ans=ans*getmi(C,solve(n-3,mod-1))%mod;

	printf("%lld\n",ans);
	return 0;
}