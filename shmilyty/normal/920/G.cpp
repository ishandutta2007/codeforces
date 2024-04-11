#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
int t,x,p,k,isp[1000001],mu[1000001];
vector<int> pri;
void pre()
{
	mu[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!isp[i])
		{
			pri.push_back(i);
			mu[i]=-1;
		}
		for(int l:pri)
		{
			if(l*i>1000000)
				break;
			isp[l*i]=1;
			if(i%l==0)
				break;
			mu[l*i]=-mu[i];
		}
	}
}
int count(int a)
{
	int res=0;
	for(int i=1;i*i<=p;i++)
		if(p%i==0)
		{
			res+=mu[i]*(a/i);
			if(i*i!=p)
				res+=mu[p/i]*(a/(p/i));
		}
	return res;
}
void writes(int x)
{
	if(x>9)
		writes(x/10);
	putchar(x%10+'0');
}
void solve()
{
	x=read(),p=read(),k=read();
	int l=x+1,r=1e7,s=count(x);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int s1=count(mid);
		if(s1-s>=k)
			r=mid-1;
		else
			l=mid+1;
	}
	writes(l);
	putchar('\n');
//	printf("%lld\n",l);
//	cout<<l<<endl;
}
signed main()
{
	pre();
	t=read();
	while(t--)
		solve();
	return 0;
}