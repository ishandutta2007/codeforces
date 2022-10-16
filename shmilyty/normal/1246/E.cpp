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
int n,k,sum,a[16];
bitset<2001> f[1<<16];
std::vector<int> v[2000];
vector<array<int,2>> ans;
void dfs(int msk,int x,int dep)
{
	if(!msk)
		return ;
	for(int i=0;i<n;i++)
		if(((msk>>i)&1)&&x>=a[i]&&f[msk^(1<<i)][x-a[i]])
		{
			v[dep].push_back(a[i]);
			dfs(msk^(1<<i),x-a[i],dep);
			return ;
		}
	dfs(msk,x*k,dep+1);
}
signed main()
{
	n=read();
	k=read();
	for(int i=0;i<n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		for(int l=0;l<n;l++)
			if((i>>l)&1)
				f[i]|=(f[i^(1<<l)]<<a[l]);
		for(int l=sum/k;l;l--)
			if(f[i][l*k])
				f[i][l]=1;
	}
	if(!f[(1<<n)-1][1])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	dfs((1<<n)-1,1,0);
	// puts("ok");
	for(int i=sum-1;~i;i--)
		if(!v[i].empty())
		{
			int tot=0;
			for(int l:v[i])
			{
				if(tot)
					cout<<tot<<" "<<l<<'\n';
				tot+=l;
				if(tot%k==0)
				{
					// cout<<i<<" "<<tot<<'\n';
					int x=i;
					while(tot%k==0)
					{
						x--;
						tot/=k;
					}
					v[x].push_back(tot);
					tot=0;
				}
			}
		}
	return 0;
}