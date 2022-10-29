#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1000005;
int n,a[N],mn,ans;

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
	n=getint();
	rep(i,1,n) a[i]=getint();
	mn=n+1;
	repd(i,n,1)
	{
		if(mn>i) ++ans;
		mn=min(mn,i-a[i]);
	}
	printf("%d\n",ans);
	return 0;
}