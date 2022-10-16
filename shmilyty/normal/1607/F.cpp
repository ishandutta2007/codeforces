//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define rg register int
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
const int N=2003,S=N*N;
int t,n,m,cnt,rt,tot,dfn,dx[26],dy[26],to[S],dis[S],vis[S];
bool ok[S];
string s[N]; 
int hsh(int x,int y)
{
	return x*(m+1)+y;
}
void dfs(int x)
{
	dis[x]=0;
	vis[x]=dfn;
	rg T=to[x];
	if(T)
	{
		if(!vis[T])
			dfs(T);
		elif(vis[T]==dfn)
			rt=x;
		dis[x]=max(dis[x],dis[T]+1);
	}
}
void work(int x)
{
	ok[x]=1;
	rg T=to[x];
	tot++;
	if(T)
		if(!ok[T])
			work(T);
	dis[x]=tot;
}
int solve(int x)
{
	if(x&&ok[x])
		return dis[x];
	return dis[x]=1+solve(to[x]); 
}
void solve()
{
	scanf("%d%d",&n,&m);
	cnt=dfn=rt=0;
	for(int i=0;i<=n+1;i++)
		for(int l=0;l<=m+1;l++)
		{
			cnt++;
			to[cnt]=ok[cnt]=vis[cnt]=0;
		}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=" "+s[i];
		for(int l=1;l<=m;l++)
			to[hsh(i,l)]=hsh(i+dx[s[i][l]-'A'],l+dy[s[i][l]-'A']);
	}
	for(int i=1;i<=cnt;i++)
		if(!vis[i])
		{
			dfn++;
			dfs(i);
			if(rt)
			{
				tot=0;
				work(rt);
				dis[i]=tot;
				solve(i);
				rt=0;		
			}
		}
	int ans=0,x,y;
	for(int i=1;i<=n;i++)
	for(int l=1;l<=m;l++)
		if(ans<dis[hsh(i,l)])
		{
			ans=dis[hsh(i,l)];
			x=i;
			y=l;
		}
	printf("%d %d %d\n",x,y,ans);
}
signed main()
{
	dx['U'-'A']=-1;
	dx['D'-'A']=1;
	dy['L'-'A']=-1;
	dy['R'-'A']=1;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}