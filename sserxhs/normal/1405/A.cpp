#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[102],t;
int n,c,fh,i;
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
		for (i=n;i;i--) printf("%d ",a[i]);puts("");
	}
}