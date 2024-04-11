#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e2+2;
int a[N],b[N],l[N];
int n,c,fh,i,tp,t;
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
		for (i=1;i<=n;i++) read(a[i]);tp=0;
		for (i=1;i<=n;i++) {read(l[i]);if (l[i]==0) b[++tp]=a[i];}
		sort(b+1,b+tp+1);
		for (i=1;i<=n;i++) if (l[i]==0) a[i]=b[tp--];
		for (i=1;i<=n;i++) printf("%d ",a[i]);puts("");
	}
}