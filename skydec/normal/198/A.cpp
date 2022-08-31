#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 1100000
typedef long long LL;
LL Pow(LL a,LL b)
{
	LL c=1;for(;b;b>>=1,a=a*a)if(b&1)c*=a;
	return c;
}
/*struct huge
{
	int len;
	int a[MAXN];
	void up()
	{
		while(a[len+1])
		{
			len++;
			a[len+1]+=a[len]/10;
			a[len]%=10;
		}
	}
	void mult(int x)
	{
		rep(i,1,len)a[i]*=x;
		rep(i,1,len){a[i+1]+=a[i]/10;a[i]%=10;}
		up();
	}
	void add(int x)
	{
		a[1]+=x;
		rep(i,1,len){a[i+1]+=a[i]/10;a[i]%=10;}
		up();
	}
}A,B;*/
LL n,t,k,b;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&k,&b,&n,&t);
	LL now=1;LL ans=0;
	while(t>=now)
	{
		if(n-ans+1<0)break;
		ans++;
		now+=Pow(k,ans)+(b-1)*Pow(k,ans-1);
	}
	int pp=0;if(n-ans+1<0)ans=0;else ans=n-ans+1;
	printf("%d\n",ans);
	return 0;
}