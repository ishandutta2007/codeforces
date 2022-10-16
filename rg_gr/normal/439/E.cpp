#include <stdio.h>
#include <unordered_map>
#define int long long
#define maxn 100005
	int N=100005;
namespace mu
{
	int mu[100005],vis[100005],prim[100005],cnt;
	inline int read()
	{
		int num=0,f=1;char c=getchar();
		while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
		while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
		return num*f;
	}
	void M(int n)
	{
	    mu[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        if(!vis[i])prim[++cnt]=i,mu[i]=-1;
	        for(int j=1;j<=cnt;j++)
	        {
	            if(prim[j]*i>n) break;
	            vis[prim[j]*i]=1;
	            if(i%prim[j]==0) break;
	            mu[i*prim[j]]=-mu[i];
	        }
	    }	
	}
	int N=100005;
	std::unordered_map<int,int> sum;
	int Getsum(int x)
	{
		if(x<=N)return mu[x];
		if(sum[x])return sum[x];
		int res=1;
		for(int l=2,r=x;l<=x;l=r+1)
		{
			r=x/(x/l);
			res-=(r-l+1)*Getsum(x/l);
		}
		return sum[x]=res;
	}
};
#define mod 1000000007
inline int qp(int x,int p)
{
    int res=1;
    while(p)
    {
        if(p&1)res=res*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return res;
}
int fac[10000005];
inline int slv(int q,int f)
{
    if(q<f)return 0;
    q--,f--;
    return fac[q]*qp(fac[f],mod-2)%mod*qp(fac[q-f],mod-2);
}
//using namespace mu;

signed main()
{
	int T=mu::read(),ans=0;
    //phi::E(N);
    //for(int i=1;i<=N;i++)phi::phi[i]+=phi::phi[i-1];
    mu::M(N);
    //for(int i=1;i<=N;i++)mu::mu[i]+=mu::mu[i-1];
    fac[0]=1;
    for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i%mod;
    while(T--)
	{
		int n=mu::read(),f=mu::read(),ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i)continue;
            ans=(ans+mu::mu[i]*slv(n/i,f))%mod;
            if(i*i!=n)ans=(ans+mu::mu[n/i]*slv(i,f))%mod;
        }
        printf("%lld\n",ans<0?ans+mod:ans);
	}
    //printf("%lld\n",ans);
	return 0;
}