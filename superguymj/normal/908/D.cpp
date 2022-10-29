#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=2005,mod=1000000007;
typedef long long LL;
int a,k,p,q;
int f[N][N],ans;

void inc(int &x,int y)
{
	if((x+=y)>=mod) x-=mod;
}

int sqr(int x)
{
	return (LL)x*x%mod;
}

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
	scanf("%d%d%d",&k,&p,&q);
	a=getmi(p+q,mod-2),p=(LL)p*a%mod,q=(LL)q*a%mod;
	f[1][0]=1;
	rep(i,1,k*2)
	{
		rep(j,0,k)
			if(f[i][j])
			{
				int tmp=f[i][j];
				if(i+j<k)
				{
					inc(f[i+1][j],(LL)tmp*p%mod);
					inc(f[i][i+j],(LL)tmp*q%mod);
				}
				else
				{
					int val=(i+j+(LL)p*getmi(1-p+mod,mod-2)%mod)%mod;
					val=(LL)val*getmi(1-p+mod,mod-2)%mod;
					inc(ans,(LL)tmp*q%mod*val%mod);
				}
			}
	}
	printf("%d\n",ans);
    return 0;
}