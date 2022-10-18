#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int N=2097154;
const double pi=3.1415926535897932384626434;
struct cp
{
	double x,y;
};//x+yi
int n,m,i,j,r[N],limit,l,cnt;
cp a[N],b[N],ys;
int ed[N];
char c;
inline void read(int &x)
{
	x=0;c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+c-48;
		c=getchar();
	}
}
inline cp operator + (cp &a,cp &b)
{
	ys.x=a.x+b.x;
	ys.y=a.y+b.y;
	return ys;
}
inline cp operator - (cp &a,cp &b)
{
	ys.x=a.x-b.x;
	ys.y=a.y-b.y;
	return ys;
}
inline cp operator * (cp &a,cp &b)
{
	ys.x=a.x*b.x-a.y*b.y;
	ys.y=a.x*b.y+a.y*b.x;
	return ys;
}
void dft(cp *a,int xs)
{
	int i,j,k;
	cp w,wn,b,c;
	for (i=0;i<limit;i++) if (i<r[i]) swap(a[i],a[r[i]]);
	for (i=1;i<limit;i<<=1)
	{
		wn.x=cos(pi/i);
		wn.y=xs*sin(pi/i);
		l=i<<1;
		for (j=0;j<limit;j+=l)
		{
			w.x=1;w.y=0;
			for (k=0;k<i;k++,w=w*wn)
			{
				b=a[j+k];c=a[i+j+k]*w;
				a[j+k]=b+c;
				a[i+j+k]=b-c;
			}
		}
	}
	if (xs==-1) for (i=0;i<limit;i++) a[i].x=a[i].x/limit;
}
int main()
{
	scanf("%d%d",&n,&m);b[0].x=1;
	while (n--)
	{
		read(i);a[i].x=b[i].x=1;ed[i]=1;
	}
	n=m;
	limit=1;l=0;
	while (limit<=n+m)
	{
		limit<<=1;
		++l;
	}
	--l;
	for (i=0;i<limit;i++) r[i]=(r[i>>1]>>1)|((i&1)<<l);
	//for (i=0;i<limit;i++) printf("%d %.2f\n",i,a[i].x);
	//for (i=0;i<limit;i++) printf("%d %.2f\n",i,b[i].x);
	dft(a,1);
	dft(b,1);
	for (i=0;i<limit;i++) a[i]=a[i]*b[i];
	dft(a,-1);
	//for (i=0;i<limit;i++) printf("%d %.2f\n",i,a[i].x);
	for (i=1;i<=m;i++) if (ed[i])
	{
		if (a[i].x<1.5) ++cnt,ed[i]=2;
	} else if (a[i].x>0.5) return puts("NO"),0;
	puts("YES");printf("%d\n",cnt);
	for (i=1;i<=m;i++) if (ed[i]==2) printf("%d ",i);
}