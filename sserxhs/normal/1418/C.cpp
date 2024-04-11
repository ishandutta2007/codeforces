#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+2;
int a[N],f[N][2];
int n,c,fh,i,t;
inline void read(int &x)
{
	c=getchar();fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
int main()
{
	read(t);
	while (t--)
	{
		read(n);
		for (i=1;i<=n;i++) read(a[i]);
		memset(f,0x3f,sizeof(f));f[0][1]=0;
		f[1][0]=a[1];
		for (i=2;i<=n;i++)
		{
			f[i][0]=min(f[i-2][1]+a[i]+a[i-1],f[i-1][1]+a[i]);
			f[i][1]=min(f[i-2][0],f[i-1][0]);
		}
		printf("%d\n",min(f[n][0],f[n][1]));
	}
}