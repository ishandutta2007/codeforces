#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+2;
int f[N];
int n,c,i,t,m,j,k,x,y,cnt,ans;
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
int getf(int x)
{
	return f[x]==x?x:f[x]=getf(f[x]);
}
int main()
{
	read(t);
	while (t--)
	{
		ans=0;
		read(n);read(m);
		for (i=1;i<=n;i++) f[i]=i;
		while (m--)
		{
			read(x);read(y);
			if (x==y) continue;
			x=getf(x);y=getf(y);
			if (x==y) {ans+=2;continue;}
			f[x]=f[y];++ans;
		}
		printf("%d\n",ans);
	}
}