#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
using namespace std;
typedef long long LL;
int mod,k;
LL ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int a[100];

LL calc(int x)
{
	LL rt=0;
	int tot=0;
	while(x) a[++tot]=x%10,x/=10;
	repd(i,tot,1) rt=rt*10+a[i];
	rep(i,1,tot) rt=rt*10+a[i];
	return rt;
}

int main()
{
	k=getint(),mod=getint();
	rep(i,1,k) ans=(ans+calc(i))%mod;
	printf("%I64d\n",ans);
	return 0;
}