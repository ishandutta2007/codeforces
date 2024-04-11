#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
int n,c,fh,i,x,y,j,m,ss[N],gs,ans=1,now,ksiz=100;
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
	read(n);m=sqrt(n);while ((m+1)*(m+1)<=n) ++m;
	for (i=2;i<=m;i++)
	{
		if (!ed[i]) ss[++gs]=i;
		for (j=1;(j<=gs)&&(ss[j]*i<=m);j++)
		{
			ed[i*ss[j]]=1;
			if (i%ss[j]==0) break;
		}
	}
	for (i=1;i<=gs;i++)
	{
		printf("B %d\n",ss[i]);
		fflush(stdout);
		read(x);printf("B %d\n",ss[i]);
		fflush(stdout);
		read(x);y=ss[i];
		while (x)
		{
			y*=ss[i];if (y>n) break;
			printf("B %d\n",y);
			fflush(stdout);
			read(x);
		}
		ans*=y/ss[i];
	}
	memset(ed,0,sizeof(ed));x=gs;gs=0;
	for (i=2;i<=n;i++)
	{
		if (!ed[i]) ss[++gs]=i;
		for (j=1;(j<=gs)&&(ss[j]*i<=n);j++)
		{
			ed[i*ss[j]]=1;
			if (i%ss[j]==0) break;
		}
	}
	printf("A 1\n");
	fflush(stdout);
	gs-=ksiz;int now;read(now);
	for (i=x+1;i<=gs;i+=ksiz)
	{
		for (j=0;j<ksiz;j++)
		{
			printf("B %d\n",ss[i+j]);
			fflush(stdout);read(x);
			if (x>1) {printf("C %d",ans*ss[i+j]);fflush(stdout);return 0;}
		}
		printf("A 1\n");
		fflush(stdout);
		read(x);
		if (x!=now-ksiz)
		{
			for (j=i;j<i+ksiz;j++)
			{
				printf("B %d\n",ss[j]);
				fflush(stdout);
				read(x);if (x) {ans*=ss[j];break;}
			}
			printf("C %d",ans);fflush(stdout);return 0;
		}now=x;
	}gs+=ksiz;
	for (;i<=gs;i++)
	{
		printf("B %d\n",ss[i]);
		fflush(stdout);
		read(x);printf("B %d\n",ss[i]);
		fflush(stdout);
		read(x);if (x) {ans*=ss[i];break;}
	}
	printf("C %d",ans);
	fflush(stdout);
}