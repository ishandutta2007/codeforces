#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+2;
int a[N];
int n,c,fh,i,t,cnt;
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
		cnt=0;
		read(n);while ((c<48)||(c>57)) c=getchar();
		a[1]=(c&1);
		for (i=2;i<=n;i++) a[i]=(getchar()&1);
		if (n&1)
		{
			for (i=1;i<=n;i+=2) if (a[i]) break;
			if (i<=n) puts("1"); else puts("2");
		}
		else
		{
			for (i=2;i<=n;i+=2) if (!a[i]) break;
			if (i<=n) puts("2"); else puts("1");
		}
	}
}