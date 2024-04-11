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
int n,m,sum,a[200001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	m=read();
	sort(a+1,a+1+n);
	while(m--)
	{
		int x=read(),y=read();
		if(a[n]>=x)
		{
			int pos=lower_bound(a+1,a+1+n,x)-a;
			int ans1=max(0ll,y-(sum-a[pos]));
			if(pos==1)
			{
				cout<<ans1<<endl;
				continue;
			}
			pos--;
			int ans2=x-a[pos]+max(0ll,y-(sum-a[pos]));
			cout<<min(ans1,ans2)<<endl;
		}
		else
			cout<<x-a[n]+max(0ll,y-(sum-a[n]))<<endl;
	}
	return 0;
}