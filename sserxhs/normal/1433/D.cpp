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
		for (i=2;i<=n;i++) if (a[i]!=a[1]) break;
		if (i>n) {puts("NO");continue;} puts("YES");
		for (i=2;i<=n;i++) if (a[i]!=a[1]) {c=i;printf("%d %d\n",1,i);}
		for (i=2;i<=n;i++) if (a[i]==a[1]) printf("%d %d\n",c,i);
	}
}