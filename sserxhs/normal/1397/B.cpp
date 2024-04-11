#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
ll ans=9e18,j,na;
int a[N];
int n,c,i;
inline ll ab(ll x)
{
	if (x>0) return x;return -x;
}
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
	//freopen("a.out","w",stdout);
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for (c=1;(n-1)*log(c)<=log((ll)a[n]*(n+2));c++)
	{
		na=0;
		for (i=j=1;i<=n;i++,j*=c) na+=ab(j-a[i]);
		if (na<ans) ans=na;
		//printf("%d %lld\n",c,na);
	}
	printf("%lld",ans);
}