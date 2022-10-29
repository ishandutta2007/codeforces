#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100000,mod=1000000007;
int x,y,lim,a,ans,p[N];
typedef long long LL;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
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

void dfs(int x,int a,int f)
{
	if(x>*p)
	{
		ans=(ans+getmi(2,a-1)*f)%mod;
		return;
	}
	dfs(x+1,a,f);
	dfs(x+1,a/p[x],-f);
}

int main()
{
	x=getint(),y=getint();
	if(y%x) return puts("0"),0;
	y/=x,a=y,lim=sqrt(y);
	rep(i,2,lim)
		if(y%i==0)
		{
			p[++*p]=i;
			while(y%i==0) y/=i;
		}
	if(y>1) p[++*p]=y;
	dfs(1,a,1);
	printf("%d\n",(ans+mod)%mod);
	return 0;
}