#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=2005;
int n,a[N],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

bool cmp(int x,int y)
{
	return (x&1)<(y&1);
}

void solve()
{
	n=getint(),ans=0;
	rep(i,1,n) a[i]=getint();
	sort(a+1,a+1+n,cmp);
	rep(i,1,n) rep(j,i+1,n) if(gcd(a[i],2*a[j])>1) ++ans;
	printf("%d\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}