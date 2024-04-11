#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
int a[N],b[N];
int n,c,fh,i,x;
bool ed[N];
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
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	if (1^n&1) {swap(a[n>>1],a[n]);--n;sort(a+1,a+n+1);}x=n>>1;
	for (i=1;i<=n;i++) if (i&1) b[i]=a[++x];x=n>>1;
	for (i=n;i;i--) if (1^i&1)
	{
		while ((x)&&(b[i-1]==a[x])) --x;
		if (!x) break;ed[x]=1;b[i]=a[x--];
	}
	x=n>>1;
	for (;i;i--) if (1^i&1)
	{
		while (ed[x]) --x;
		b[i]=a[x--];
	}c=0;
	for (i=2;i<=n;i+=2) if ((b[i]<b[i-1])&&(b[i]<b[i+1])) ++c;
	printf("%d\n",c);
	for (i=1;i<=n;i++) printf("%d ",b[i]);
	if (a[n+1]) printf("%d",a[n+1]);
}