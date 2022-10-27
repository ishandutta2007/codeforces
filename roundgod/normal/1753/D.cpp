#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,m,p,q;
vector<string> str;
vector<P> G[MAXN];
ll d[MAXN];
int id(int x,int y)
{
    return x*m+y;
}
void add_edge(int u,int v,int w)
{
    G[u].push_back(P(v,w));
}
void dijkstra()
{
    priority_queue<P,vector<P>,greater<P> > que;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(str[i][j]=='.') {d[id(i,j)]=0; que.push(P(0,id(i,j)));} else d[id(i,j)]=INF;
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.S;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            P e=G[v][i];
            if(d[e.F]>d[v]+e.S)
            {
                d[e.F]=d[v]+e.S;
                que.push(P(d[e.F],e.F));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=0;i<n;i++) 
    {
        string s;
        cin>>s;
        str.push_back(s);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='L')
            {
                if(j-1>=0&&str[i][j-1]!='#') add_edge(id(i,j-1),id(i,j+1),q);
                if(j+2<m&&str[i][j+2]!='#') add_edge(id(i,j+2),id(i,j),q);
                if(i+1<n&&j+1<m&&str[i+1][j+1]!='#') add_edge(id(i+1,j+1),id(i,j),p);
                if(i-1>=0&&j+1<m&&str[i-1][j+1]!='#') add_edge(id(i-1,j+1),id(i,j),p);
                if(i+1<n&&str[i+1][j]!='#') add_edge(id(i+1,j),id(i,j+1),p);
                if(i-1>=0&&str[i-1][j]!='#') add_edge(id(i-1,j),id(i,j+1),p);
            }
            if(str[i][j]=='U')
            {
                if(i-1>=0&&str[i-1][j]!='#') add_edge(id(i-1,j),id(i+1,j),q);
                if(i+2<n&&str[i+2][j]!='#') add_edge(id(i+2,j),id(i,j),q);
                if(i+1<n&&j+1<m&&str[i+1][j+1]!='#') add_edge(id(i+1,j+1),id(i,j),p);
                if(j-1>=0&&i+1<n&&str[i+1][j-1]!='#') add_edge(id(i+1,j-1),id(i,j),p);
                if(j+1<m&&str[i][j+1]!='#') add_edge(id(i,j+1),id(i+1,j),p);
                if(j-1>=0&&str[i][j-1]!='#') add_edge(id(i,j-1),id(i+1,j),p);
            }
        }
    dijkstra();
    ll ans=INF;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='#') continue;
            if(i+1<n&&str[i+1][j]!='#') ans=min(ans,d[id(i,j)]+d[id(i+1,j)]);
            if(j+1<m&&str[i][j+1]!='#') ans=min(ans,d[id(i,j)]+d[id(i,j+1)]);
        }
    if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    return 0;
}