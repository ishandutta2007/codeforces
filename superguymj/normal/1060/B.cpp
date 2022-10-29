#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int tot,a[100000],b[100000],ans;
int x,w;
long long n;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int main()
{
	scanf("%lld",&n),tot=0;
	while(n) a[++tot]=n%10,n/=10;
	rep(i,2,tot)
	{
		while(a[i-1]+b[i-1]+10<=18)
		{
			--a[i],x=10;
			w=min(x,9-b[i-1]);
			b[i-1]+=w,x-=w,a[i-1]+=x;
		}
	}
	rep(i,1,tot) ans+=a[i]+b[i];
	printf("%d\n",ans);
	return 0;
}