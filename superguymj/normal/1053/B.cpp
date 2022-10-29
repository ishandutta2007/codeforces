#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=300005,lim=130;
typedef long long LL;
int n,a[N],s[N],S[N][2],bin[N];
LL ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL getLL()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint();
	rep(i,1,65535) bin[i]=bin[i^(i&-i)]+1;
	rep(i,1,n)
	{
		LL x=getLL();
		a[i]=bin[x&65535]+bin[(x>>16)&65535]+bin[(x>>32)&65535]+bin[(x>>48)&65535];
	}
	rep(i,1,n) s[i]=(s[i-1]+a[i])%2;
	repd(i,n,1) S[i][0]=S[i+1][0]+(s[i]==0),S[i][1]=S[i+1][1]+(s[i]==1);
	rep(i,1,n)
	{
		if(i+lim<n)
		{
			int tp=s[i-1];
			ans+=S[i+lim+1][tp];
		}
		int mx=0,sum=0;
		rep(j,i,min(n,i+lim))
		{
			mx=max(mx,a[j]),sum+=a[j];
			if(mx*2<=sum && !(sum&1)) ++ans;
		}
	}
	printf("%lld\n",ans);
	return 0;
}