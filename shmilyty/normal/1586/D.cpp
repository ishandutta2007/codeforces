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
int n,lst=1,a[101];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cout<<"? ";
		for(int l=1;l<n;l++)
			cout<<"1 ";
		cout<<i<<endl;
		int k=read();
		if(k)
			lst=i;
	}
	a[n]=n+1-lst;
	for(int i=1;i<=n;i++)
	{
		if(i==a[n])
			continue;
		if(i<a[n])
		{
			cout<<"? ";
			for(int l=1;l<n;l++)
				cout<<a[n]-i+1<<" ";
			cout<<1<<endl;
			a[read()]=i;
		}
		else
		{
			cout<<"? ";
			for(int l=1;l<n;l++)
				cout<<1<<" ";
			cout<<i-a[n]+1<<endl;
			a[read()]=i;
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}