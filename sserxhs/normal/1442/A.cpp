#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e4+2;
ll l;
int a[N];
int n,t,i;
inline void read(register int &x)
{
	register int c=getchar();
	while (c<48||c>57) c=getchar();
	x=c^48;c=getchar();
	while (c>=48&&c<=57) x=x*10+(c^48),c=getchar();
}
int main()
{
	read(t);
	while (t--)
	{
		read(n);
		for (i=1;i<=n;i++) read(a[i]);
		for (i=n;i;i--) a[i]-=a[i-1];l=0;
		for (i=2;i<=n;i++) if (a[i]<0) l+=a[i];
		if (a[1]+l<0) puts("NO"); else puts("YES");
	}
}