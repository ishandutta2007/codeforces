#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+2,p=998244353;
int a[N],b[N];
int n,c,i,t,m,j,k,ans,la,s;
inline void read(register int &x)
{
	register int c=getchar(),fh=1;
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
		sort(a+1,a+n+1);int ans=1;
		for (i=2;i<=n;i++)
		{
			if (a[i]<=a[i-1]) ++a[i];
			if (a[i]!=a[i-1]) ++ans;
		}printf("%d\n",ans);
	}
}