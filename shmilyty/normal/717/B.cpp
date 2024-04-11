#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int n,a,b,ans,c[20001]; 
bool check(int x)
{
	int cnt=(x/a)+1;
	for(int i=0;i<=20000;i++)
		c[i]=i+1;
	for(int i=1;cnt<n&&i*b<=x;i++)
		for(int l=0;cnt<n&&i*b+l*a<=x;l++)
		{
			cnt+=c[l];
			if(l)
				c[l]+=c[l-1]; 
		}
	if(cnt<n)
		return 0;
	return 1;
}
int solve(int x)
{
	int cnt=(x/a)+1,sum=cnt*(cnt-1)/2*a;
	for(int i=0;i<=20000;i++)
		c[i]=i+1;
	for(int i=1;i*b<=x;i++)
		for(int l=0;i*b+l*a<=x;l++)
		{
			cnt+=c[l];
			sum+=c[l]*(i*b+l*a);
			if(l)
				c[l]+=c[l-1];
		}
	return sum-(cnt-n)*x;
}
signed main()
{
	n=read()-1;
	a=read();
	b=read();
	if(a>b)
		swap(a,b);
	ans=(a+b)*n;
	if(n==1||a==0)
	{
		cout<<ans;
		return 0;
	}
	int l=0,r=a*n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<ans+solve(l);
	return 0;
}