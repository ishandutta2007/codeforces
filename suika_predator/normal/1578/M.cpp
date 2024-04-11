#include<bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x1,long long &y1)
{
//	cerr<<"exgcd "<<a<<' '<<b<<endl;
	if(!b)
	{
		x1=1,y1=0;
		return a;
	}
	long long x2,y2;
	long long d=exgcd(b,a%b,x2,y2);
	x1=y2,y1=x2-(a/b)*y2;
	return d;
}
const int p=998244353,g=3,invg=(p+1)/g;//3 is primitive root of p
int poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=p;
		x*=x,x%=p;
		y>>=1;
	}
	return ret;
}
int getlog(int x)
{
	const int B=40000;
	long long p1[B+5],pb[B+5];
	map<int,int> mp;
	p1[0]=pb[0]=1;
	mp[1]=0;
	for(int i=1;i<=B;i++)
	{
		p1[i]=p1[i-1]*invg%p;
		mp[p1[i]]=i;
	}
	long long gb=p1[B];
	for(int i=1;i<=B;i++)
	{
		pb[i]=pb[i-1]*gb%p;
		if(mp.contains(pb[i]*x%p))
		{
			return i*B-mp[pb[i]*x%p];
		}
	}
	return 0;
}
const int MOD=p-1;
//let f[i]=3**g[i] mod p <---> g[i]=log_3(f[i])
//g[i]=(b[1]*g[i-1]+b[2]*g[i-2]+...+b[k]*g[i-k])mod (p-1)
//let g[k]=x
//g[i]/x=(b[1]*g[i-1]/x+b[2]*g[i-2]/x+...+b[k]*g[i-k]/x)mod (p-1)
//g[n]/x= the answer if g[k]=1
int k;
struct mat
{
	int a[111][111];
	mat(int x=0)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				a[i][j]=(i==j?x:0);
	}
	mat operator*(const mat &m)const
	{
		mat ret;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				for(int t=1;t<=k;t++)
				{
					ret.a[i][t]=(ret.a[i][t]+1ll*a[i][j]*m.a[j][t])%MOD;
				}
			}
		}
		return ret;
	}
};
int b[233];


int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>k;
	mat ans(1),mul;
	for(int i=1;i<=k;i++)cin>>b[i];
	cin>>n>>m;
	for(int i=1;i<k;i++)
	{
		mul.a[i+1][i]=1;
	}
	for(int i=1;i<=k;i++)
	{
		mul.a[i][k]=b[k+1-i];
	}
	/*
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<mul.a[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<ans.a[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	long long y=n-k;
	while(y)
	{
		if(y&1)ans=ans*mul;
		mul=mul*mul;
		y>>=1;
	}
	/*
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<mul.a[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<ans.a[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	long long tmp=ans.a[k][k];
//	cerr<<"calc "<<tmp<<endl;
	//g**(x*tmp)=m
	long long z=getlog(m);
//	cerr<<z<<' '<<poww(g,z)<<endl;
	//x*tmp+y*(p-1)=z
	long long x=0;
	y=0;
	long long d=exgcd(tmp,MOD,x,y);
	if(z%d!=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	x=((x*z/d)%MOD+MOD)%MOD;
	cout<<poww(g,x)<<endl;
	return 0;
}