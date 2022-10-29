#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n;
long long a[N<<1],ans;

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
	rep(i,1,2*n) a[i]=getint();
	sort(a+1,a+1+2*n);
	ans=(a[n]-a[1])*(a[2*n]-a[n+1]);
	rep(i,2,n) ans=min(ans,(a[2*n]-a[1])*(a[i+n-1]-a[i]));
	printf("%lld\n",ans);
	return 0;
}