#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,sum,L,a[300001],f[300001];
int exgcd(int a,int b,int &x,int &y)
{
	int d=a; 
	if(b==0)
	{
		x=1;
		y=0;
	}
	else
	{
		d=exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
	return d;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		sum+=y;
		a[i]=x-y;
	}
	sort(a+1,a+1+n,greater<int>());
	f[0]=sum;
	L=n;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
		if(a[i]<0&&a[i-1]>=0)
			L=i-1;
	}
	// cout<<L<<'\n';
	m=read();
	while(m--)
	{
		int x=read(),y=read(),X,Y,k;
		int g=exgcd(x,y,X,Y);
		if(n%g)
		{
			puts("-1");
			continue;
		}
		X*=n/g;
		Y*=n/g;
		int p=y/g,q=x/g;
		if(X<0)
		{
			k=ceil((-1.0*X)/p);
			X+=p*k;
			Y-=q*k;
		}
		elif(X>0)
		{
			k=X/p;
			X-=p*k;
			Y+=q*k;
		}
		// cout<<X<<" "<<Y<<'\n';
		if(Y>=0)
		{
			int num=Y/q;
			if((X+num*p)*x<=L)
				cout<<f[(X+num*p)*x]<<'\n';
			else
			{
				if(L<=X*x)
				{
					cout<<f[X*x]<<'\n';
					continue ;
				}
				int lb=((L-X*x)/(p*x)*p+X),rb=lb+p;
				cout<<max(f[lb*x],rb*x<=min(n,(X+num*p)*x)?f[rb*x]:0)<<'\n';
			}
		}
		else
			puts("-1");
	}
	return 0;
}