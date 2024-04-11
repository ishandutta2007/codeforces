#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second

const int maxn=300005;

int n,m;
vector<pair<int,bool> >graf[maxn];
int low[maxn],no[maxn],lp=1,cnt=1;
bool vis[maxn];
int spoj[maxn];
int fu[maxn],p[maxn];
bool ok[maxn],skarb[maxn];

int fin(int a)
{
	if(fu[a]==a)
		return a;
	return fu[a]=fin(fu[a]);
}

void un(int a,int b)
{
	fu[fin(a)]=fin(b);
}

int dfs(int a,int oj)
{
	vis[a]=true;
	no[a]=low[a]=lp++;
	for(auto v:graf[a])
	{
		if(v.st==oj)
			continue;
		if(!vis[v.st])
			low[a]=min(low[a],dfs(v.st,a));
		else
			low[a]=min(low[a],no[v.st]);
		
	}
	if(low[a]<no[a])
		un(a,oj);
	return low[a];
}

void dfs2(int a,int oj)
{
	p[a]=oj;
	
	for(auto v:graf[a])
	{
		if(p[v.st]==0){
			skarb[v.st]=skarb[a];
			if(v.nd)
				skarb[v.st]=true;
			dfs2(v.st,a);
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fu[i]=i;
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		graf[a].push_back({b,c});
		graf[b].push_back({a,c});
	}
	dfs(1,1);
	
	int x,y;
	cin>>x>>y;
	dfs2(x,x);
	
	if(skarb[y]){
		cout<<"YES\n";
		return 0;
	}	
	
	while(y!=x)
	{
		ok[fin(y)]=true;
		y=p[y];
	}
	ok[fin(x)]=true;
	
	for(int i=1;i<=n;i++){
		if(ok[fin(i)])
		{
			for(auto v:graf[i])
			{
				if(ok[fin(v.st)] && v.nd)
				{
					cout<<"YES\n";
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
		
		
		
		
	
	return 0;
}