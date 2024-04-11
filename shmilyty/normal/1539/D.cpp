#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int n,cnt,tot,sum;
pair<int,int> p[100001],q[100001];
bool check(int x)
{
	cnt=n,tot=x;
	for(int i=1;i<=n;i++)
		q[i]=p[i];
	while(q[cnt].second<=x&&cnt!=0)
	{
		x-=q[cnt].second;
		cnt--;
	}
	q[cnt].second-=x;
	for(int i=1;i<=cnt;i++)
		if(q[i].first>tot)
			return 0;
		else
			tot+=q[i].second;
	return 1; 
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		sum+=x;
		p[i]={y,x};
	}
	sort(p+1,p+1+n);
	int l=0,r=sum;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l+sum<<endl;
	return 0;
}