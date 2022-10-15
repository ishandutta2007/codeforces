#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<P> points;
vector<int> sx,sy;
vector<int> gx[MAXN],gy[MAXN];
bool used[2*MAXN];
vector<pair<int,P> > h,v;
bool intersect(pair<int,P> x,pair<int,P> y)
{
	return (x.F>y.S.F&&x.F<y.S.S&&y.F>x.S.F&&y.F<x.S.S);
}
vector<int> G[2*MAXN];
int mx[2*MAXN],my[2*MAXN];
queue<int> que;
int dx[2*MAXN],dy[2*MAXN];
bool vis[2*MAXN];
bool find(int u)
{
    for(int i=0;i<G[u].size();i++)
    {
        if(!vis[G[u][i]]&&dy[G[u][i]]==dx[u]+1)
        {
            vis[G[u][i]]=true;
            if(!my[G[u][i]]||find(my[G[u][i]]))
            {
                mx[u]=G[u][i];
                my[G[u][i]]=u;
                return true;
            }
        }
    }
    return false;
}
int matching()
{
    memset(mx,0,sizeof(mx));
    memset(my,0,sizeof(my));
    int ans=0;
    while(true)
    {
        bool flag=false;
        while(!que.empty()) que.pop();
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        for(int i=1;i<=n;i++)
            if(!mx[i]) que.push(i);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=0;i<G[u].size();i++)
                if(!dy[G[u][i]])
                {
                    dy[G[u][i]]=dx[u]+1;
                    if(my[G[u][i]])
                    {
                        dx[my[G[u][i]]]=dy[G[u][i]]+1;
                        que.push(my[G[u][i]]);
                    }
                    else flag=true;
                }
        }
        if(!flag) break;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            if(!mx[i]&&find(i)) ans++;
    }
    return ans;
}
void dfs(int v)
{
	vis[v]=true;
	for(auto to:G[v])
	{
		if(v<=n&&to>n&&mx[v]==to) continue;
		if(v>n&&to<=n&&my[v]!=to) continue;
		if(!vis[to]) dfs(to);
	}
}
int getx(int id)
{
	return sx[id-1];
}
int gety(int id)
{
	return sy[id-1];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		points.push_back(P(x,y));
		sx.push_back(x); sy.push_back(y);
	}
	sort(sx.begin(),sx.end()); sx.erase(unique(sx.begin(),sx.end()),sx.end());
	sort(sy.begin(),sy.end()); sy.erase(unique(sy.begin(),sy.end()),sy.end());
	for(auto p:points)
	{
		int x=p.F,y=p.S;
		x=lower_bound(sx.begin(),sx.end(),x)-sx.begin()+1;
		y=lower_bound(sy.begin(),sy.end(),y)-sy.begin()+1;
		gx[x].push_back(y); gy[y].push_back(x);
	}
	int szx=(int)sx.size(),szy=(int)sy.size();
	for(int i=1;i<=szx;i++) 
	{
		sort(gx[i].begin(),gx[i].end());
		for(int j=0;j<(int)gx[i].size()-1;j++) v.push_back(make_pair(i,P(gx[i][j],gx[i][j+1])));
	}
	for(int i=1;i<=szy;i++) 
	{
		sort(gy[i].begin(),gy[i].end());
		for(int j=0;j<(int)gy[i].size()-1;j++) h.push_back(make_pair(i,P(gy[i][j],gy[i][j+1])));
	}
	n=(int)v.size(); m=(int)h.size();
	assert(n<=1000&&m<=1000);
	for(int i=0;i<(int)v.size();i++)
		for(int j=0;j<(int)h.size();j++)
			if(intersect(v[i],h[j])) 
			{
				G[i+1].push_back((int)v.size()+j+1);
				G[(int)v.size()+j+1].push_back(i+1);
			}
	int res=szx+szy+matching();
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!mx[i]) dfs(i);
	int ansx=szx,ansy=szy;
	for(int i=1;i<=n;i++) if(!vis[i]) ansx++;
	for(int i=n+1;i<=n+m;i++) if(vis[i]) ansy++;
	printf("%d\n",ansy);
	int cnt=n;
	for(int i=1;i<=szy;i++) 
	{
		int last=0;
		for(int j=0;j<(int)gy[i].size()-1;j++)
		{
			cnt++;
			if(vis[cnt])
			{
				printf("%d %d %d %d\n",getx(gy[i][last]),gety(i),getx(gy[i][j]),gety(i));
				last=j+1;
			} 
		}
		printf("%d %d %d %d\n",getx(gy[i][last]),gety(i),getx(gy[i].back()),gety(i));
	}
	printf("%d\n",ansx);
	cnt=0;
	for(int i=1;i<=szx;i++) 
	{
		int last=0;
		for(int j=0;j<(int)gx[i].size()-1;j++)
		{
			cnt++;
			if(!vis[cnt])
			{
				printf("%d %d %d %d\n",getx(i),gety(gx[i][last]),getx(i),gety(gx[i][j]));
				last=j+1;
			} 
		}
		printf("%d %d %d %d\n",getx(i),gety(gx[i][last]),getx(i),gety(gx[i].back()));
	}
	return 0;
}