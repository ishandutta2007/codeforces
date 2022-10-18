#include <bits/stdc++.h>
using namespace std;
const int N=3e5+2;
int a[N];
int t,n,i,c;
inline void read(register int &x)
{
	register int c=getchar();
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
	read(t);
	while (t--)
	{
		read(n);
		for (i=1;i<=n;i++) read(a[i]);c=1;
		for (i=2;i<=n;i++) if (a[i]>a[c]) c=i;
		for (i=1;i<=n;i++) if (a[i]!=a[c]) break;
		if (i>n) puts("-1"); else
		{
			if ((c!=1)||(n==1)||(a[1]>a[2])) printf("%d\n",c);
			else
			{
				printf("%d\n",i-1);
			}
		}
	}
}