#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int t,n,top,flag,l,r,a[2022];
vector<int> ans;
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	ans.clear();
	for(int i=1;i<=n;i++)
		if((i&1)!=(a[i]&1))
		{
			puts("-1");
			return ;
		}
	for(int i=n;i>1;i-=2)
	{
		int pos=1;
		for(int l=1;l<=i;l++)
			if(a[l]==i)
			{
				pos=l;
				break;
			}
		ans.push_back(pos);
		reverse(a+1,a+1+pos);
		for(int l=1;l<=i;l++)
			if(a[l]==i-1)
			{
				pos=l;
				break;
			}
		ans.push_back(pos-1);
		reverse(a+1,a+pos);
		ans.push_back(pos+1);
		reverse(a+1,a+pos+2);
		ans.push_back(3);
		reverse(a+1,a+4);
		ans.push_back(i);
		reverse(a+1,a+1+i);
	}
	cout<<(int)ans.size()<<endl;
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