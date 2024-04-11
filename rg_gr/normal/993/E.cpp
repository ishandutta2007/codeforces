#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <queue>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
#define int long long
struct I{
	double a,b;
	I(double a=0,double b=0):a(a),b(b){}
	I operator+(const I& x)const
	{
		return (I){(a+x.a),(b+x.b)};
	}
	I operator-(const I& x)const
	{
		return (I){(a-x.a),(b-x.b)};
	}
	I operator*(const I& x)const
	{
		return (I){(a*x.a-b*x.b),(b*x.a+a*x.b)};
	}
};
template<typename T>
T qp(T x,int p)
{
	T res(1);
	while(p)
	{
		if(p&1)res=res*x;
		x=x*x;
		p>>=1;
	}
	return res;
}
int r[4000005];I t,pp;
const double p=3.1415926535897932;
void FFT(int o,I* a,int C)
{
	for(int i=0;i<o;i++)
		if(i<r[i])t=a[i],a[i]=a[r[i]],a[r[i]]=t;
	for(int i=1;i<o;i<<=1)
	{
		I x(cos(p/i),C*sin(p/i));
		for(int j=0;j<o;j+=(i<<1))
		{
			I y(1,0);
			for(int k=0;k<i;k++,y=y*x)
			{
				t=a[j+i+k]*y;pp=a[j+k];
				a[j+k]=pp+t;a[j+i+k]=pp-t;
			}
		}
	}
}
I a[4000005],b[4000005];int u[1000005];
signed main()
{
	int n=read(),m=n,mm=read(),l=0,x=0,p=0,s=0;a[0].a=1;
	for(int i=1;i<=n;i++)x+=u[i]=read()<mm,a[x].a++;
	for(int i=0;i<=n;i++)b[i].a=a[n-i].a;
	int o=1;while(o<=n+m)o<<=1,l++;    
	for(int i=0;i<o;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	//for(int i=0;i<=n;i++)printf("%lld ",(int)(a[i].a+0.5));puts("");
	//for(int i=0;i<=n;i++)printf("%lld ",(int)(b[i].a+0.5));puts("");
	FFT(o,a,1);FFT(o,b,1);
	for(int i=0;i<=o;i++)a[i]=a[i]*b[i];
	FFT(o,a,-1);u[n+1]=1;
	for(int i=1;i<=n+1;i++)u[i]?p+=s*(s+1)/2,s=0:s++;
	printf("%lld ",p);
	for(int i=1;i<=n;i++)printf("%lld ",(long long)(a[i+n].a/o+0.5));
}