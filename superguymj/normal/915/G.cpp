#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=2000005,mod=1000000007;
bool vis[N];
int n,k,flv[N],f[N<<1],ans,mu[N],prm[N];

int getmi(int a,int x)
{
	int rt=1;
	while(x)
	{
		if(x&1) rt=(LL)rt*a%mod;
		a=(LL)a*a%mod,x>>=1;
	}
	return rt;
}

int main()
{
	scanf("%d%d",&n,&k);
	rep(i,1,k) flv[i]=getmi(i,n);
	mu[1]=1;
	rep(i,2,k)
	{
		if(!vis[i]) prm[++*prm]=i,mu[i]=-1;
		rep(j,1,*prm)
		{
			if(i*prm[j]>k) break;
			vis[i*prm[j]]=1;
			if(i%prm[j]) mu[i*prm[j]]=-mu[i];
			else break;
		}
	}
	
	rep(i,1,k)
		if(mu[i])
		{
			for(int j=i,nw=1; ; ++nw,j+=i)
			{
				f[j]=((LL)f[j]+mu[i]*(flv[nw]-flv[nw-1]))%mod;
				if(j>=k) break;
			}
		}
	rep(i,1,k) ans=(ans+((f[i]=((f[i]+f[i-1])%mod+mod)%mod)^i))%mod;
	printf("%d\n",ans);
	return 0;
}