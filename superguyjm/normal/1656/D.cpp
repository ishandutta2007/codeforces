#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
LL n;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void solve()
{
	scanf("%lld",&n);
	LL x=1;
	while(!(n&1)) n>>=1,x<<=1;
	if(n==1) puts("-1");
	else
	{
		if(n<=2*x-1) printf("%lld\n",n);
		else printf("%lld\n",x*2);
	}
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}