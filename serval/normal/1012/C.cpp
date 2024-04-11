#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5005;
int f[maxn][maxn>>1][2];
int n,i,j,mid,ret;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0xff,sizeof(f));
	f[0][0][0]=0;
	a[0]=a[n+1]=0xC0000000;
	for (i=1;i<=n;i++)
	{
		mid=(i+1)>>1;
		for (j=0;j<=mid;j++)
		{
			f[i][j][0]=f[i-1][j][0];
			if (f[i-1][j][1]>=0)
				if (f[i][j][0]<0||f[i-1][j][1]+max(0,a[i]-a[i-1]+1)<f[i][j][0])
					f[i][j][0]=f[i-1][j][1]+max(0,a[i]-a[i-1]+1);
		}
		for (j=1;j<=mid;j++)
		{
			if (f[i-1][j-1][0]>=0)
				if (f[i][j][1]<0||f[i-1][j-1][0]+max(0,a[i-1]-a[i]+1)<f[i][j][1])
					f[i][j][1]=f[i-1][j-1][0]+max(0,a[i-1]-a[i]+1);
			if (i>2&&f[i-2][j-1][1]>=0)
				if (f[i][j][1]<0||f[i-2][j-1][1]+max(0,a[i-1]-min(a[i],a[i-2])+1)<f[i][j][1])
					f[i][j][1]=f[i-2][j-1][1]+max(0,a[i-1]-min(a[i],a[i-2])+1);
		}
	}
	for (i=1;i<=mid;i++)
	{
		ret=-1;
		for (j=1;j<=n;j++)
			if (f[j][i][1]>=0)
				if (ret<0||f[j][i][1]+max(0,a[j+1]-a[j]+1)<ret)
					ret=f[j][i][1]+max(0,a[j+1]-a[j]+1);
		printf(i==mid?"%d\n":"%d ",ret);
	}
	return 0;
}