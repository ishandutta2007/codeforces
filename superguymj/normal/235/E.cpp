#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=2005,mod=1073741824;
bool vis[N];
int a,b,c,mu[N],prm[N];
typedef long long LL;
LL ans;

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

void prepare()
{
	mu[1]=1;
	rep(i,2,2000)
	{
		if(!vis[i]) prm[++*prm]=i,mu[i]=-1;
		rep(j,1,*prm)
		{
			if(i*prm[j]>2000) break;
			vis[i*prm[j]]=1;
			if(i%prm[j]) mu[i*prm[j]]=-mu[i];
			else break;
		}
	}
}

LL query(int x,int y)
{
	LL rt=0;
	rep(i,1,x)
		if(gcd(i,y)==1)
			rt+=x/i;
	return rt;
}

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	prepare();
	rep(i,1,a)
		rep(j,1,min(b,c))
			if(gcd(i,j)==1)
				ans=(ans+a/i*mu[j]*query(b/j,i)*query(c/j,i))%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}