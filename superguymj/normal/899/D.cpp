#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
LL ans;
int n;
const int bin[]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999};

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint();
	if(n<=4) {printf("%d\n",n*(n-1)/2); return 0;} 
	int tot=n+n-1,p;
	rep(i,1,9) if(bin[i]<=tot) p=i;
	int nw=0;
	while(nw*(bin[p]+1ll)+bin[p]<=tot)
	{
		long long x=nw*(bin[p]+1ll)+bin[p];
		int fir=max(1ll,x-n),sed=min((LL)n,x-1);
		ans+=sed-fir+1,++nw;
	}
	printf("%I64d\n",ans/2);
	return 0;
}