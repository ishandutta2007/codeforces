#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
int a[N];
int n,c,fh,i,t,m,cnt;
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
		read(n);read(m);
		for (i=1;i<=n;i++) read(a[i]);cnt=1;
		for (i=2;i<=n;i++) if (a[i]!=a[i-1]) ++cnt;
		if (m>1)
		{
			if (cnt==1) puts("1"); else printf("%d\n",(cnt-2)/(m-1)+1);
		} else if (cnt==1) puts("1"); else puts("-1");
	}
}