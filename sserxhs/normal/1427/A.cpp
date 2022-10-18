#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[52];
int n,c,fh,i,t,tot;
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
		sort(a+1,a+n+1);
		tot=0;for (i=1;i<=n;i++) tot+=a[i];
		if (tot==0) {puts("NO");continue;}puts("YES");
		if (tot>0) for (i=n;i;i--) printf("%d ",a[i]); else for (i=1;i<=n;i++) printf("%d ",a[i]);puts("");
	}
}