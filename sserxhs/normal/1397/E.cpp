#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+2;
ll f[N][2];
int a[N];
int r,rr,rrr,d,n,i,c;
inline void read(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
int main()
{
	memset(f,0x3f,sizeof(f));
	read(n);read(r);read(rr);read(rrr);read(d);
	for (i=1;i<=n;i++) read(a[i]);
	f[0][1]=-d;
	for (i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][1]+d+min((ll)rr,(ll)r*(a[i]+1));
		f[i][1]=min(f[i-1][1]+d+(ll)r*a[i]+rrr,f[i-1][0]+d*3ll+r+min((ll)rr+r,(ll)r*a[i]+min(rrr,r<<1)));
	}i=n;
	f[n][1]=min(f[i-1][1]+d+(ll)r*a[i]+rrr,f[i-1][0]+d*2ll+r+min((ll)rr+r+d,(ll)r*a[i]+min((ll)rrr,(ll)d+(r<<1))));
	printf("%lld",min(f[n][1],f[n][0]+d*2ll+r));
}