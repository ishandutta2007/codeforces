#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=105,mod=1000000007;
typedef long long LL;
int n;
struct D{int u,v;} dat[N];
LL f[N],g[N],ans[N],mxt[N][N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

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

LL get(int n)
{
	LL ret=1;
	rep(i,1,n)
	{
		int p=0;
		rep(j,i,n) if(mxt[j][i]) p=j;
		if(i!=p) ret=-ret,swap(mxt[i],mxt[p]);
		ret=ret*mxt[i][i]%mod;
		LL inv=getmi(mxt[i][i],mod-2);
		rep(j,1,n) mxt[i][j]=mxt[i][j]*inv%mod;
		rep(j,1,n) if(j!=i)
		{
			LL t=mxt[j][i];
			rep(k,1,n) mxt[j][k]=(mxt[j][k]-t*mxt[i][k])%mod;
		}
	}
	return ret;
}

int main()
{
	n=getint();
	rep(i,1,n-1)
	{
		int u=getint(),v=getint();
		dat[i]=(D){u,v};
	}
	rep(i,0,n-1)
	{
		rep(j,1,n) rep(k,1,n)
		{
			if(j==k) mxt[j][k]=n-1;
			else mxt[j][k]=-1;
		}
		rep(j,1,n-1)
		{
			int u=dat[j].u,v=dat[j].v;
			--mxt[u][u],--mxt[v][v];
			++mxt[u][v],++mxt[v][u];
			
			mxt[u][u]+=i,mxt[v][v]+=i;
			mxt[u][v]-=i,mxt[v][u]-=i;
		}
		f[i]=get(n-1);
	}
	rep(i,0,n-1)
	{
		rep(j,0,n-1) g[j]=0;
		LL inv=1;
		g[0]=1;
		rep(j,0,n-1) if(i!=j)
		{
			inv=inv*getmi(i-j,mod-2)%mod;
			repd(k,n-1,0)
			{
				g[k]=g[k]*(-j)%mod;
				if(k) g[k]=(g[k]+g[k-1])%mod;
			}
		}
		rep(j,0,n-1) ans[j]=(ans[j]+g[j]*f[i]%mod*inv)%mod;
	}
	rep(i,0,n-1) printf("%lld ",(ans[i]+mod)%mod);
	puts("");
	return 0;
}