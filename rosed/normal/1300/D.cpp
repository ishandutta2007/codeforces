#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
#define y1 z7z_Eta
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1) 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=3e5+10;
	int n;
	struct point
	{
		int x,y;
	}a[N];
	inline int sqr(int x){return x*x;}
	inline double dis(int x1,int y1,int x2,int y2)
	{
		return sqrt(sqr(x1-x2)+sqr(y1-y2));
	}
	inline double slope(point a,point b)
	{
		double k=1.0*(b.y-a.y)/(1.0*(b.x-a.x));
		return k;
	}
	inline void main()
	{
		n=read();
		if(n&1)
		{
			puts("nO");
			return;
		}
		for(int i=1;i<=n;++i)
		{
			a[i].x=read(),a[i].y=read();
			a[i+n]=a[i];
			a[i+n+n]=a[i];
		}
		int t=n>>1;
		++t;
		for(int i=1;i<=n;++i)
		{
			if(fabs(slope(a[i],a[i+1])-slope(a[t+1],a[t]))>eps)
			{
				puts("nO");
				return;
			}
			if(fabs(dis(a[i].x,a[i].y,a[i+1].x,a[i+1].y)-dis(a[t].x,a[t].y,a[t+1].x,a[t+1].y))>eps)
			{
				puts("nO");
				return;
			}
			++t;
		}
		puts("YES"); 
	}
}
signed main()
{

	red::main();
	return 0;
}