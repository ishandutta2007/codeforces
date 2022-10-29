#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int N=200005;
int n,q;
LL a[N];

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
	n=getint(),q=getint();
	rep(i,1,n) a[i]=getint();
	sort(a+1,a+1+n);
	rep(i,1,n) a[i]+=a[i-1];
	while(q--)
	{
		int x=getint(),y=getint();
		printf("%lld\n",a[n-x+y]-a[n-x]);
	}
	return 0;
}