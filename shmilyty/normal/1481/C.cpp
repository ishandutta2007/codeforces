#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
int t,n,m,last,flag,a[100001],b[100001],c[100001],ans[100001];
vector<int> v[100001];
void solve()
{
	n=read();
	m=read();
	flag=0;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		if(b[i]!=a[i])
			v[b[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
		c[i]=read(); 
	if(v[c[m]].size())
	{
		ans[m]=last=v[c[m]].back();
		v[c[m]].pop_back();
	}
	else
	{
		for(int i=1;i<=n;i++)	
			if(b[i]==c[m])
			{
				ans[m]=last=i;
				flag=1;
				break;
			}
		if(!flag)
		{
			puts("No");
			return ;
		}
	}
	for(int i=m-1;i>=1;i--)
		if(v[c[i]].size())
		{
			ans[i]=v[c[i]].back();
			v[c[i]].pop_back();
		}
		else
			ans[i]=last;
	for(int i=1;i<=n;i++)
		if(v[i].size()!=0)
		{
			puts("No");
			return ;
		}
	puts("Yes");
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main()
{	
	t=read();
	while(t--)
		solve();
	return 0;
}