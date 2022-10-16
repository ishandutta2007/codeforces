#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,n,a[10001];
int query(int ty,int i,int l,int x)
{
	cout<<"? "<<ty<<" "<<i<<" "<<l<<" "<<x<<endl;
	cout.flush();
	return read(); 
}
void solve()
{
	n=read();
	int mn=min(query(2,1,2,1),query(2,2,1,1));
	int mx=max(query(1,1,2,n-1),query(1,2,1,n-1));
	a[1]=mx;
	a[2]=mn;
	int minn=2,maxx=1;
	if(query(2,1,2,mn)==mn)
	{
		swap(a[1],a[2]);
		swap(minn,maxx);
	}
	for(int i=3;i<=n;i++)
	{
		if((a[minn]-1)>(n-a[maxx]))
		{
			int x=query(2,i,maxx,1);
			if(x==a[maxx])
				a[i]=query(1,maxx,i,n-1);
			else
				a[i]=x;
		}
		else
		{
			int x=query(1,minn,i,n-1);
			if(x==a[minn])
				a[i]=query(2,i,minn,1);
			else
				a[i]=x;
		}
		if(a[i]<a[minn])
			minn=i;
		if(a[i]>a[maxx])
			maxx=i;	
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}