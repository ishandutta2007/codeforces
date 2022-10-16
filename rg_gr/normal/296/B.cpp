// Problem: CF296B Yaroslav and Two Strings
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF296B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
//#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while((c<'0'||c>'9')&&c!='?')c=getchar();
	return c=='?'?-1:c^48;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
#define int long long
const int mod = 1000000007;
int qp(int x,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=res*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return res;
}
struct Mod{
	long long x;
	Mod(int x=0):x(x){}
	Mod operator=(const int& xx)
	{
		x=xx;
		return *this;
	}
	Mod operator+(const Mod &b)
	{
		return (Mod)((x+b.x)%1000000007);
	}
	Mod operator-(const Mod &b)
	{
		return (Mod)((x-b.x+1000000007)%1000000007);
	}
	Mod operator*(const Mod &b)
	{
		return (Mod)((x*b.x)%1000000007);
	}
	Mod operator/(const Mod &b)
	{
		return (Mod)(x*qp(b.x,1000000005)%1000000007);
	}
	Mod operator^(const Mod &b)
	{
		return (Mod)(qp(x,b.x));
	}
	Mod operator+(const int &b)
	{
		return (Mod)((x+b)%1000000007);
	}
	Mod operator-(const int &b)
	{
		return (Mod)((x-b+1000000007)%1000000007);
	}
	Mod operator*(const int &b)
	{
		return (Mod)((x*b)%1000000007);
	}
	Mod operator*=(const int &b)
	{
		x=x*b;
		x%=mod;
		return *this;
	}
	Mod operator+=(const int &b)
	{
		x=x+b;
		x%=mod;
		return *this;
	}
	Mod operator*=(const Mod &b)
	{
		x=x*b.x;
		x%=mod;
		return *this;
	}
	Mod operator+=(const Mod &b)
	{
		x=x+b.x;
		x%=mod;
		return *this;
	}
	Mod operator/(const int &b)
	{
		return (Mod)(x*qp(b,1000000005)%1000000007);
	}
	Mod operator^(const int &b)
	{
		return (Mod)(qp(x,b));
	}
	bool operator==(const int &b)
	{
		return x==b;
	}
};
typedef Mod arr[300005];
arr b,s,e;
int x[300005],y[300005];
signed main()
{
	int n=read();
	Mod cnt=1;
	for(int i=0;i<n;i++)x[i]=re1d()+1,x[i]==0?cnt*=10:0;
	for(int i=0;i<n;i++)y[i]=re1d()+1,y[i]==0?cnt*=10:0;
	Mod awa=1;
	for(int i=0;i<n;i++)
	{
		if(x[i]&&y[i])
		{
			if(x[i]<y[i])
			{
				awa=0;
				break;
			}
			b[i]=i?b[i-1]:1;
		}
		else if(x[i])
		{
			b[i]=i?b[i-1]:1;
			b[i]*=x[i];
		}
		else if(y[i])
		{
			b[i]=i?b[i-1]:1;
			b[i]*=(11-y[i]);
		}
		else
		{
			b[i]=i?b[i-1]:1;
			b[i]*=55;
		}
		awa=b[i];
	}
	Mod qaq=1;
	for(int i=0;i<n;i++)
	{
		if(x[i]&&y[i])
		{
			if(x[i]>y[i])
			{
				qaq=0;
				break;
			}
			s[i]=i?s[i-1]:1;
		}
		else if(y[i])
		{
			s[i]=i?s[i-1]:1;
			s[i]*=y[i];
		}
		else if(x[i])
		{
			s[i]=i?s[i-1]:1;
			s[i]*=(11-x[i]);
		}
		else
		{
			s[i]=i?s[i-1]:1;
			s[i]*=55;
		}
		qaq=s[i];
	}
	Mod qwq=1;
	for(int i=0;i<n;i++)
	{
		if(x[i]&&y[i])
		{
			if(x[i]==y[i])e[i]=i?e[i-1]:1;
			else
			{
				qwq=0;
				break;
			}
		}
		else if(x[i]==y[i])
		{
			e[i]=i?e[i-1]:1;
			e[i]*=10;
		}
		else e[i]=i?e[i-1]:1;
		qwq=e[i];
//		oldb(e[i]);
	}
	oldl((cnt-qaq-awa+qwq).x);
	return 0;
}