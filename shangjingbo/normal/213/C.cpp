#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;

const int shift =   1001;
const int inf   =   1000000000;
const int maxn  =   305*305*2;
const int maxm  =   maxn*(1+4)*2;
const int dx[]  =   {0,1,0,-1};
const int dy[]  =   {1,0,-1,0};

int head[maxn],vtx[maxm],next[maxm],c[maxm],cost[maxm],tot;
int dist[maxn],pre[maxn],s,t,n,flow,Tcost; 
bool vis[maxn];

inline void add(int a,int b,int cc,int cst)
{
    vtx[tot]=b;
    next[tot]=head[a];
    c[tot]=cc;
    cost[tot]=cst;
    head[a]=tot++;
    
    vtx[tot]=a;
    next[tot]=head[b];
    c[tot]=0;
    cost[tot]=-cst;
    head[b]=tot++;
}

inline void spfa()
{
    for (int i=0;i<n*n;++i) dist[i]=-inf;
    memset(vis,false,sizeof(vis));
    queue<int> q;
    q.push(s);
    dist[s]=0;
    vis[s]=true;
    while (q.size()){
        int u=q.front();
        vis[u]=false;
        q.pop();
//printf("%d %d\n",u,dist[u]);
        for (int p=head[u];p;p=next[p])
        if (c[p] && dist[vtx[p]]<dist[u]+cost[p]){
            dist[vtx[p]]=dist[u]+cost[p];
            pre[vtx[p]]=p;
            if (!vis[vtx[p]]){
                q.push(vtx[p]);
                vis[vtx[p]]=true;
            }
        }
    }
printf("dist=   %d\n",dist[t]);
    int u,p;
    for (u=t;u!=s;u=vtx[p]){
        p=pre[u];
        --c[p];
        ++c[p^=1];
    }
    Tcost+=dist[t];
    ++flow;
}

int f[605][305][305];
int a[305][305];

int main()
{
    scanf("%d",&n);
    tot=2;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    
    for (int i=0;i<=n+n;++i)
        for (int x1=0;x1<n;++x1)
            for (int x2=0;x2<n;++x2)
                f[i][x1][x2]=-inf;
    
    
    f[0][0][0]=a[0][0];
    for (int s=0;s<n-1+n-1;++s){
        for (int x1=0;x1<n && x1<=s;++x1){
            int y1=s-x1;
            if (y1<0 || y1>=n) continue;
            for (int x2=0;x2<n && x2<=s;++x2){
                int y2=s-x2;
                if (y2<0 || y2>=n) continue;
                for (int k1=0;k1<2;++k1){
                    int tx1=x1+dx[k1],ty1=y1+dy[k1];
                    if (tx1<0 || ty1<0 || tx1>=n || ty1>=n) continue;
                    for (int k2=0;k2<2;++k2){
                        int tx2=x2+dx[k2],ty2=y2+dy[k2];
                        if (tx2<0 || ty2<0 || tx2>=n || ty2>=n) continue;
                        
                        int delta=a[tx1][ty1];
                        if (tx2!=tx1 || ty2!=ty1) delta+=a[tx2][ty2];
                        f[s+1][tx1][tx2]=max(f[s][x1][x2]+delta,f[s+1][tx1][tx2]);
                    }
                }
            }
        }
    }
    
    printf("%d\n",f[n-1+n-1][n-1][n-1]);
    
    /*s=0,t=n*n*2-1;
    flow=Tcost=0;
    spfa();
    spfa();
    
    printf("%d\n",Tcost-shift*(n+n-1)*2);*/
    
    return 0;
}