#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ss[200002][2],ys[200002];
int n,c,fh,i,gs,gss,t,m,j,k;
bool ed[200002];
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
inline int fd(int x)
{
	return lower_bound(ys+1,ys+gss+1,x)-ys;
}
int main()
{
	read(t);
	while (t--)
	{
		memset(ed+1,0,gss);
		gs=gss=0;
		read(n);m=sqrt(n);while ((m+1)*(m+1)<=n) ++m;
		for (i=2;i<=m;i++) if (n%i==0)
		{
			ys[++gss]=i;
			if (i*i!=n) ys[++gss]=n/i;
		}ys[++gss]=n;
		sort(ys+1,ys+gss+1);
		for (i=2;i<=m;i++) if (n%i==0)
		{
			ss[++gs][0]=i;ss[gs][1]=1;
			while ((n=n/i)%i==0) ++ss[gs][1];
		}
		if (n!=1) {ss[++gs][0]=n;ss[gs][1]=1;}
		if (gs<=1)
		{
			for (i=1,j=ss[gs][0];i<=ss[gs][1];i++,j*=ss[gs][0]) printf("%d ",j);puts("\n0");
			continue;
		}
		if ((gs==2))
		{
			if ((ss[1][1]==1)&&(ss[2][1]==1)) printf("%d %d %d\n1\n",ss[1][0],ss[1][0]*ss[2][0],ss[2][0]);
			else
			{
				if (ss[1][1]==1) {swap(ss[1][1],ss[2][1]);swap(ss[1][0],ss[2][0]);}
				ed[fd(ss[1][0]*ss[2][0])]=ed[fd(ss[1][0]*ss[1][0]*ss[2][0])]=ed[fd(ss[1][0])]=ed[fd(ss[2][0])]=1;
				printf("%d ",ss[1][0]*ss[2][0]);
				for (i=1;i<=gss;i++) if ((!ed[i])&&(ys[i]%ss[1][0]==0))
				{
					ed[i]=1;
					printf("%d ",ys[i]);
				}
				printf("%d %d ",ss[1][0],ss[1][0]*ss[1][0]*ss[2][0]);
				for (i=1;i<=gss;i++) if (!ed[i]) printf("%d ",ys[i]);printf("%d\n",ss[2][0]);
				puts("0");
			}
			continue;
		}ss[0][0]=ss[gs][0];
		for (i=1;i<=gs;i++) ed[fd(ss[i][0])]=ed[fd(ss[i][0]*ss[i-1][0])]=1;
		for (i=1;i<=gs;i++)
		{
			printf("%d ",ss[i][0]*ss[i-1][0]);
			for (j=1;j<=gss;j++) if ((!ed[j])&&(ys[j]%ss[i][0]==0)) {printf("%d ",ys[j]);ed[j]=1;}
			printf("%d ",ss[i][0]);
		}puts("\n0");
	}
}