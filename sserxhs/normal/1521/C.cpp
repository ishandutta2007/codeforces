#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
std::mt19937 rnd(time(0));
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
template<typename typC> void read(register typC &x)
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
template<typename typC> void write(register typC x)
{
	if (x<0) putchar('-'),x=-x;
	static int st[100];
	register int tp=1;
	register typC y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(register typC *a,register int num)
{
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int N=1e6+2,M=1e6+2,p=998244353;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
char s[N];
int a[N],b[N],c[N],d[N],ans[N];
int T,n,m,i,j,k,x,y,z,la;
int main()
{
	T=1;read(T);
	while (T--)
	{
		read(n);//m=n;//if (n&1) --n;
		for (i=1;i+1<=n;i+=2)
		{
			printf("? %d %d %d %d\n",1,i,i+1,n-1);
			fflush(stdout);
			read(a[i]);//mx
			if (a[i]==n-1)
			{
				printf("? %d %d %d %d\n",1,i+1,i,n-1);
				fflush(stdout);
				read(a[i]);
			}
			printf("? %d %d %d %d\n",2,i,i+1,1);
			fflush(stdout);
			read(b[i]);//mn
			if (b[i]==2)
			{
				printf("? %d %d %d %d\n",2,i+1,i,1);
				fflush(stdout);
				read(b[i]);
			}
		}
		if (n==3)
		{
			i=1;
			printf("? %d %d %d %d\n",1,i,i+2,n-1);
			fflush(stdout);
			read(c[i]);//mx
			if (c[i]==n-1)
			{

			printf("? %d %d %d %d\n",1,i+2,i,n-1);
			fflush(stdout);
			read(c[i]);//mx
			}
			printf("? %d %d %d %d\n",2,i,i+2,1);
			fflush(stdout);
			read(d[i]);//mn
			if (d[i]==2)
			{

			printf("? %d %d %d %d\n",2,i+2,i,1);
			fflush(stdout);
			read(d[i]);//mn
			}
			if (c[i]==a[i])
			{
				ans[i]=a[i];
				ans[i+1]=b[i];
				ans[i+2]=d[i];
			} else if (d[i]==a[i])
			{
				//if (c[i]==-1||b[i]==-1) while (1);
				//assert(c[i]==b[i]);
				ans[i]=a[i];
				ans[i+1]=b[i];
				ans[i+2]=c[i];
			}
			else
			{
				ans[i]=b[i];
				ans[i+1]=a[i];
				if (d[i]==b[i]) ans[i+2]=c[i]; else ans[i+2]=d[i];
			}
		}
		else{
		for (i=1;i+3<=n;i+=4)
		{
			printf("? %d %d %d %d\n",1,i,i+2,n-1);
			fflush(stdout);
			read(c[i]);//mx
			if (c[i]==n-1)
			{

			printf("? %d %d %d %d\n",1,i+2,i,n-1);
			fflush(stdout);
			read(c[i]);//mx
			}
			printf("? %d %d %d %d\n",2,i,i+2,1);
			fflush(stdout);
			read(d[i]);//mn
			if (d[i]==2)
			{

			printf("? %d %d %d %d\n",2,i+2,i,1);
			fflush(stdout);
			read(d[i]);//mn
			}
			if (c[i]==a[i+2])
			{
				ans[i+2]=a[i+2];
				ans[i+3]=b[i+2];
				ans[i]=d[i];
				ans[i+1]=a[i]+b[i]-d[i];
			}
			else if (c[i]==b[i+2])
			{
				ans[i+2]=b[i+2];
				ans[i+3]=a[i+2];
				ans[i]=d[i];
				ans[i+1]=a[i]+b[i]-d[i];
			}
			else if (c[i]==a[i])
			{
				ans[i]=a[i];
				ans[i+1]=b[i];
				ans[i+2]=d[i];
				ans[i+3]=a[i+2]+b[i+2]-d[i];
			} else
			{
				if (c[i]==-1||b[i]==-1) while (1);
				assert(c[i]==b[i]);
				ans[i]=b[i];
				ans[i+1]=a[i];
				ans[i+2]=d[i];
				ans[i+3]=a[i+2]+b[i+2]-d[i];
			}
		}
		for (;i<=n;i++)
		{
			printf("? %d %d %d %d\n",1,1,i,n-1);
			fflush(stdout);read(x);
			if (x==n-1)
			{

			printf("? %d %d %d %d\n",1,i,1,n-1);
			fflush(stdout);read(x);
			}
			printf("? %d %d %d %d\n",2,1,i,1);
			fflush(stdout);read(y);
			if (y==2)
			{

			printf("? %d %d %d %d\n",2,i,1,1);
			fflush(stdout);read(y);
			}
			if (x==ans[1]) ans[i]=y; else ans[i]=x;
		}}
		printf("!");
		for (i=1;i<=n;i++) printf(" %d",ans[i]);puts("");fflush(stdout);//return 0;
	}
}