#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+2;
int a[N];
int n,c,fh,i,t,x,tot;
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
		read(n);read(x);tot=0;
		for (i=1;i<=n;i++) read(a[i]);
		for (i=1;i<=n;i++) if (a[i]!=x) break;
		if (i>n) {puts("0");continue;}
		for (i=1;i<=n;i++) if (a[i]==x) {puts("1");break;}
		if (i<=n) continue;
		for (i=1;i<=n;i++) tot+=a[i];
		if (x*n==tot) puts("1"); else puts("2");
	}
}