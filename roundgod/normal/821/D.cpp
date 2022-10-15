#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,c[MAXN],r[MAXN];
struct edge
{
	int to,cost;
};
vector<edge> G[MAXN];
map<P,int> mp;
int V,d[4*MAXN];
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int id=-1;
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&r[i],&c[i]);
		if(r[i]==n&&c[i]==m) id=i;
		mp[P(r[i],c[i])]=i;
	}
	for(int i=0;i<k;i++)
	{
		if(mp.find(P(r[i]-1,c[i]))!=mp.end()) G[i].push_back((edge){mp[P(r[i]-1,c[i])],0});
		if(mp.find(P(r[i]+1,c[i]))!=mp.end()) G[i].push_back((edge){mp[P(r[i]+1,c[i])],0});
		if(mp.find(P(r[i],c[i]-1))!=mp.end()) G[i].push_back((edge){mp[P(r[i],c[i]-1)],0});
		if(mp.find(P(r[i],c[i]+1))!=mp.end()) G[i].push_back((edge){mp[P(r[i],c[i]+1)],0});
	}
	for(int i=0;i<k;i++)
	{
		if(r[i]!=1) G[i].push_back((edge){k+r[i]-2,1});
		G[i].push_back((edge){k+r[i]-1,1});
		if(r[i]!=n) G[i].push_back((edge){k+r[i],1});
		if(r[i]!=1) G[k+r[i]-2].push_back((edge){i,0});
		if(r[i]!=n) G[k+r[i]].push_back((edge){i,0});
		G[k+r[i]-1].push_back((edge){i,0});
		if(c[i]!=1) G[i].push_back((edge){k+n+c[i]-2,1});
		G[i].push_back((edge){k+n+c[i]-1,1});
		if(c[i]!=m) G[i].push_back((edge){k+n+c[i],1});
		G[k+n+c[i]-1].push_back((edge){i,0});
		if(c[i]!=1) G[k+n+c[i]-2].push_back((edge){i,0});
		if(c[i]!=m) G[k+n+c[i]].push_back((edge){i,0});
	}
	//G[k+n-2].push_back((edge){k+n+m,1});
	G[k+n-1].push_back((edge){k+n+m,0});
	G[k+n+m-1].push_back((edge){k+n+m,0});
	//G[k+n+m-2].push_back((edge){k+n+m,1});
	V=k+n+m+1;
	dijkstra(0);
	if(id==-1) printf("%d\n",d[k+n+m]==INF?-1:d[k+n+m]); else printf("%d\n",d[id]==INF?-1:d[id]);
	return 0;
}