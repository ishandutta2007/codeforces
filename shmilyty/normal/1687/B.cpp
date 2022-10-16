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
int n,m,ans,lst,q[501];
array<int,2> a[501];
int query()
{
	cout<<"? ";
	for(int i=1;i<=m;i++)
		cout<<q[i];
	cout<<endl;
	return read();
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		q[i]=1;
		a[i]={query(),i};
		q[i]=0;
	}
	sort(a+1,a+1+m);
	fill(q+1,q+1+m,1);
	lst=query();
	ans=a[1][0];
	for(int i=m-1;i;i--)
	{
		q[a[i+1][1]]=0;
		int x=query();
		if(x+a[i+1][0]==lst)
			ans+=a[i+1][0];
		lst=x;
	}
	cout<<"! "<<ans;
	return 0;
}