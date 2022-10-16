#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define int long long
const int mod=1000003;
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57)f=(c=='-'?-1:f),c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
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
		return (Mod)((x+b.x)%1000003);
	}
	Mod operator-(const Mod &b)
	{
		return (Mod)((x-b.x+1000003)%1000003);
	}
	Mod operator*(const Mod &b)
	{
		return (Mod)((x*b.x)%1000003);
	}
	Mod operator/(const Mod &b)
	{
		return (Mod)(x*qp(b.x,1000001)%1000003);
	}
	Mod operator^(const Mod &b)
	{
		return (Mod)(qp(x,b.x));
	}
	Mod operator+(const int &b)
	{
		return (Mod)((x+b)%1000003);
	}
	Mod operator-(const int &b)
	{
		return (Mod)((x-b+1000003)%1000003);
	}
	Mod operator*(const int &b)
	{
		return (Mod)((x*b)%1000003);
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
		return (Mod)(x*qp(b,1000001)%1000003);
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
inline void swap(Mod &x,Mod &y)
{
	Mod t=x;
	x=y;
	y=t;
}
Mod a[105][105];
inline int query(int x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	return read();
}
Mod qwq(int p)
{
	Mod ans=0;
	for(int i=14;i>=0;i--)ans=ans*p+a[i][15];
	return ans;
}
signed main()
{
	const int n=15;
	for(int i=0;i<n;i++)
	{
		Mod q=1;
		for(int j=0;j<n;j++)a[i][j]=q,q=q*i;
		a[i][n]=query(i);
	}
//	for(int i=0;i<n;i++,puts(""))for(int j=0;j<=n;j++)printf("%lld ",a[i][j]);
	for(int i=0;i<n;i++)
	{
		int amxn=i;
		for(int j=i+1;j<n;j++)if((a[j][i].x)>(a[amxn][i].x))amxn=j;
		for(int j=0;j<=n;j++)swap(a[i][j],a[amxn][j]);
//		if((a[i][i]==0))return puts("No Solution")&0;
		//if(a[i][i]==0)break;
	//	for(int i=0;i<n;i++,puts(""))
	//		for(int j=0;j<=n;j++)printf("%.2lf ",a[i][j]);puts("");
	//puts("why??");
		if(a[i][i].x)for(int j=i+1;j<=n;j++)a[i][j]=a[i][j]/a[i][i];
		if(a[i][i].x)a[i][i]=1;
		for(int j=0;j<n;j++)
		{
			if(i^j)
			{
				for(int k=i+1;k<=n;k++)a[j][k]=a[j][k]-a[j][i]*a[i][k];
				a[j][i]=0;
			}
		}
			
		
	//	for(int i=0;i<n;i++,puts(""))
	//		for(int j=0;j<=n;j++)printf("%.2lf ",a[i][j]);puts("");
	}
	//for(int i=0;i<n;i++)printf("%.2lf\n",a[i][n]);
	for(int i=0;i<mod;i++)
	{
		if(qwq(i)==0)
		{
			printf("! %lld\n",i);
			fflush(stdout);
			return 0;
		}
	}
	puts("! -1");
	fflush(stdout);
	return 0;
}