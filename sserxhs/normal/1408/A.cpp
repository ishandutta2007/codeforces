#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e2+2;
int a[N],b[N],d[N];
int n,c,fh,i,t,fir,lst;
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
		for (i=1;i<=n;i++) read(b[i]);
		for (i=1;i<=n;i++) read(d[i]);
		fir=lst=a[1];printf("%d ",a[1]);
		for (i=2;i<n;i++)
		{
			if (a[i]!=lst) printf("%d ",lst=a[i]); else if (b[i]!=lst) printf("%d ",lst=b[i]); else printf("%d ",lst=d[i]);
		}
		if ((a[n]!=lst)&&(a[n]!=fir)) printf("%d\n",a[n]);
		else if ((b[n]!=lst)&&(b[n]!=fir)) printf("%d\n",b[n]);
		else if ((d[n]!=lst)&&(d[n]!=fir)) printf("%d\n",d[n]);
	}
}