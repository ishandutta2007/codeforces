#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,m,k,a[101],b[101];
vector<int> ans;
void solve()
{
	k=read();
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
		b[i]=read();
	int c1=0,c2=0;
	ans.clear();
	while(c1<n||c2<m)
	{
		if(c1!=n)
		{
			if(a[c1+1]==0)
			{
				c1++;
				k++;
				ans.push_back(0);
				continue;
			}
			else
				if(k>=a[c1+1])
				{
					c1++;
					ans.push_back(a[c1]);
					continue;
				}
		}
		if(c2!=m)
		{
			if(b[c2+1]==0)
			{
				c2++;
				k++;
				ans.push_back(0);
				continue;
			}
			else
				if(k>=b[c2+1])
				{
					c2++;
					ans.push_back(b[c2]);
					continue;
				}
		}
		puts("-1");
		return ;
	}
	for(int i:ans)
		cout<<i<<" ";	
	cout<<endl;
 } 
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}