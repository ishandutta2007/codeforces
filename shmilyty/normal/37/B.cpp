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
int n,Max,reg,sum,atk,cnt,ans,vis[1001];
array<int,2> a[1001],out[1001];
signed main()
{
	n=read();
	sum=Max=read();
	reg=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={x,y};
	}
	while(1)
	{
		sum=min(Max,sum-atk+reg);
		if(sum<=0)
			break;
		if(sum==Max)
		{
			bool ok=1;
			for(int i=1;i<=n;i++)
				if(a[i][0]==100&&!vis[i])
				{
					ok=0;
					break;
				}
			if(ok)
			{
				puts("NO");
				return 0;
			}
		}
		int nxt=0,id=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&a[i][0]*Max>=sum*100&&a[i][1]>nxt)
			{
				nxt=a[i][1];
				id=i;
			}
		if(id)
		{
			vis[id]=1;
			atk+=nxt;
			out[++cnt]={ans,id};
		}
		ans++; 
	}
	puts("YES");
	cout<<ans<<" "<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<out[i][0]<<" "<<out[i][1]<<endl;
	return 0;
}