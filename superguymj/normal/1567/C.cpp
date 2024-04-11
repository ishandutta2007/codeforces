#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
typedef long long LL;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;	
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve()
{
	int n=getint();
	int p=1,x=n,a=0,b=0;
	while(x) a+=p*(x%10),x/=10,b+=p*(x%10),x/=10,p*=10;
	printf("%lld\n",(LL)(a-1)*(b+1)+b*2);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}