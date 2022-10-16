#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
struct node{
	int to,nxt,vis;
}e[600001];
int n,top,cnt,tot=-1,h[500001],stk[600001];
map<int,int> mp,num[500001];
vector<int> v[500001];
void add(int x,int y)
{
	e[++tot]={y,h[x],0};
	h[x]=tot;
}
void dfs(int x)
{
	for(int &i=h[x];~i;i=e[i].nxt)
		if(!e[i].vis)
		{
			e[i].vis=e[i^1].vis=1;
			dfs(e[i].to);
		}
	stk[++top]=x;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		while(x--)
		{
			v[i].push_back(read());
			mp[v[i].back()];
		}
	}
	for(auto &i:mp)
		i.second=++cnt;
	for(int i=1;i<=n+cnt;i++)
		h[i]=-1;
	for(int i=1;i<=n;i++)
		for(int l:v[i])
		{
			add(i,mp[l]+n);
			add(mp[l]+n,i);
		}
	for(int i=1;i<=n;i++)
	{
		top=0;
		dfs(i);
		if(stk[1]!=stk[top])
		{
			puts("No");
			return 0;
		}
		for(int l=2;l<=top;l++)
			if(stk[l-1]<=n)
				num[stk[l-1]][stk[l]-n]++;
	}
	for(int i=1;i<=n+cnt;i++)
		for(int l=h[i];~l;l=e[l].nxt)
			if(!e[l].vis)
			{
				puts("No");
				return 0;
			}
	puts("Yes"); 
	for(int i=1;i<=n;i++)
	{
		for(int l:v[i])
			if(num[i][mp[l]])
			{
				num[i][mp[l]]--;
				cout<<'L';
			}
			else
				cout<<'R';
		cout<<'\n';
	}
	return 0;
}