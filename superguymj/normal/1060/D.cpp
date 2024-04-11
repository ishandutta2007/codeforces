#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n;
long long a[N],b[N],ans;

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
	ans=n=getint();
	rep(i,1,n) scanf("%lld%lld",&a[i],&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	rep(i,1,n) ans+=max(a[i],b[i]);
	printf("%lld\n",ans);
	return 0;
}