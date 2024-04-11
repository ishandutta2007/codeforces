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
struct node{
	int id,val;
}b[200010];
int t,n,p,a[200010],vis[200010];
bool cmp(node x,node y)
{
	return x.val<y.val;
}
void solve()
{
	n=read();
	p=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i].id=i;
		b[i].val=a[i];
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)
		vis[i]=0;
	int ans=0,res=n-1;
	for(int i=1;i<=n;i++)
		if(!vis[b[i].id])
		{
			if(b[i].val>=p)
				break;
			int l=b[i].id,r=b[i].id;
			while(!(a[l]%b[i].val)&&l>=1)
			{
				l--;
				if(vis[l+1]==1)
					break;
			}
			while(!(a[r]%b[i].val)&&r<=n)
			{
				r++;
				if(vis[r-1]==1)
					break;
			}
			l++;
			r--;
			for(int j=l;j<r;j++)
			{
				vis[j]++;
				vis[j+1]++;
			}
			ans+=(r-l)*b[i].val;
			res-=(r-l);
		}
	cout<<ans+res*p<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}