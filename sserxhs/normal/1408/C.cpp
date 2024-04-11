#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
const double eps=1e-6;
int a[N];
int n,c,fh,i,j,t,l,v,vv;
double ans,dt,x,y;
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
		ans=0;
		read(n);read(l);
		for (i=1;i<=n;i++) read(a[i]);a[0]=0;a[n+1]=l;i=1;j=n;x=0;y=l;
		v=vv=1;
		while (i<=j)
		{
			dt=min((a[i]-x)/v,(y-a[j])/vv);
			ans+=dt;x+=dt*v;y-=dt*vv;
			if (fabs(a[i]-x)<eps) ++i,++v;
			if (fabs(y-a[j])<eps) --j,++vv;
			//printf("%d %d %.2f %.2f %.5f\n",i,j,x,y,dt);
		}
		ans+=(y-x)/(v+vv);printf("%.10f\n",ans);
	}
}