#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+2;
int a[N];
int n,c,fh,i,t,x,m;
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
		while (((c<48)||(c>49))&&(c!='?')) c=getchar();
		a[1]=c;x=0;
		for (i=2;i<=n;i++) a[i]=getchar();
		for (i=1;i<=n-m;i++) if (a[i]!='?')
		{
			if (a[i+m]==(a[i]^1)) {puts("NO");x=1;break;} else a[i+m]=a[i];
		}
		if (x) continue;
		for (i=n;i>m;i--) if (a[i]!='?')
		{
			if (a[i-m]==(a[i]^1)) {puts("NO");x=1;break;} else a[i-m]=a[i];
		}
		if (x) continue;n=0;
		for (i=1;i<=m;i++) if (a[i]==48) ++n; else if (a[i]==49) ++x;
		m>>=1;if ((x>m)||(n>m)) puts("NO"); else puts("YES");
	}
}