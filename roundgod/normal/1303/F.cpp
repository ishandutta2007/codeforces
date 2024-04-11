#include<bits/stdc++.h>
#define MAXN 305
#define MAXQ 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define dec sadkoasdk
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,p[MAXN*MAXN],r[MAXN*MAXN];
int col[MAXN][MAXN];
int id(int x,int y)
{
    return (x-1)*m+y;
}
struct node
{
    int x,y,t;
};
vector<node> add[MAXQ],dec[MAXQ];
int cur,delta[MAXQ];
void init()
{
    for(int i=1;i<=n*m;i++)
    {
        p[i]=i;
        r[i]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            col[i][j]=-1;
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    cur--;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;i++)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        dec[col[x][y]].push_back((node){x,y,i});
        col[x][y]=c;
        add[col[x][y]].push_back((node){x,y,i});
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dec[col[i][j]].push_back((node){i,j,q+1});
    for(int i=0;i<=2000000;i++)
    {
        if(!add[i].size()) continue;
        init();
        for(auto p:add[i])
        {
            cur=1;
            col[p.x][p.y]=i;
            if(p.x!=1&&col[p.x-1][p.y]==i) unite(id(p.x,p.y),id(p.x-1,p.y)); 
            if(p.x!=n&&col[p.x+1][p.y]==i) unite(id(p.x,p.y),id(p.x+1,p.y)); 
            if(p.y!=1&&col[p.x][p.y-1]==i) unite(id(p.x,p.y),id(p.x,p.y-1)); 
            if(p.y!=m&&col[p.x][p.y+1]==i) unite(id(p.x,p.y),id(p.x,p.y+1)); 
            delta[p.t]+=cur;
        }
    }
    for(int i=0;i<=2000000;i++)
    {
        if(!dec[i].size()) continue;
        init();
        reverse(dec[i].begin(),dec[i].end());
        for(auto p:dec[i])
        {
            cur=1;
            col[p.x][p.y]=i;
            if(p.x!=1&&col[p.x-1][p.y]==i) unite(id(p.x,p.y),id(p.x-1,p.y)); 
            if(p.x!=n&&col[p.x+1][p.y]==i) unite(id(p.x,p.y),id(p.x+1,p.y)); 
            if(p.y!=1&&col[p.x][p.y-1]==i) unite(id(p.x,p.y),id(p.x,p.y-1)); 
            if(p.y!=m&&col[p.x][p.y+1]==i) unite(id(p.x,p.y),id(p.x,p.y+1)); 
            delta[p.t]-=cur;
        }
    }
    int ans=1;
    for(int i=1;i<=q;i++)
    {
        ans+=delta[i];
        printf("%d\n",ans);
    }
    return 0;
}