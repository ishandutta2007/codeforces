#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
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
int n,k,tot,cnt=1,t[40000001][2],v[40000001];
long long ans=0;
void add(int x)
{
	int now=1;
	for(int i=29;i>=0;i--)
	{
		v[now]++;
		int y=((x>>i)&1);
		if(!t[now][y])
			t[now][y]=++cnt;
		now=t[now][y];
	}
	v[now]++;
}
int query(int x)
{
//	cout<<x<<endl;
	int now=1,res=0,cur=0,dep=0;
	for(int i=29;i>=0;i--)
	{
		int y=((x>>i)&1),z=((k>>i)&1);
//		cout<<y<<endl;
		if(now==0)
			break;
		if(!z)
		{
			res+=v[t[now][y^1]];
			now=t[now][y];
		}
		else
			now=t[now][y^1];
	}
	if(now)
		res+=v[now];
//	cout<<endl;
	return res;
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		add(tot);
		tot^=x;
		ans+=query(tot);
	}
	cout<<ans<<endl;
	return 0;
}