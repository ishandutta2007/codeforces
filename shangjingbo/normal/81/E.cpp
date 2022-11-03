#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double _x,double _y){x=_x;y=_y;}
    inline void read(){scanf("%lf%lf",&x,&y);}
    inline void show(){printf("%lf %lf\n",x,y);}
    inline double norm(){ return sqrt( sqr(x)+sqr(y) ); }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline Tpoint operator *(const Tpoint &a,const double &b){ return Tpoint(a.x*b,a.y*b); }
inline Tpoint operator /(const Tpoint &a,const double &b){ return Tpoint(a.x/b,a.y/b); }
inline double det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }
//=============================================================================================

#define maxn 100005

struct node
{
    int total,couple;
    node(){}
    node(int a,int b){total=a;couple=b;}
};

inline bool operator <(const node &a,const node &b)
{
    return a.total<b.total || a.total==b.total && a.couple<b.couple;
}

inline node operator +(const node &a,const node &b)
{
    return node(a.total+b.total,a.couple+b.couple);
}

int sex[maxn],next[maxn];
queue<int> q;
VI son[maxn];
vector< pair<int,int> > ans;

inline node Cost(int a,int b)
{
    return node(1,sex[a]!=sex[b]);
}

node f[maxn][2],g[maxn],GG[maxn];
int pre[maxn][2],h[maxn],HH[maxn],n,d[maxn];

inline void printTree(int u,int stat)
{
    if (stat==0)
    {
        for (int i=0;i<son[u].size();++i)
        {
            int v=son[u][i];
            if (f[v][0]<f[v][1]) printTree(v,1);
            else printTree(v,0);
        }
    }else
    {
        ans.PB(MP(u,pre[u][stat]));
        for (int i=0;i<son[u].size();++i)
        {
            int v=son[u][i];
            if (v==pre[u][stat]) printTree(v,0);
            else
            {
                if (f[v][0]<f[v][1]) printTree(v,1);
                else printTree(v,0);
            }
        }
    }
}

int a[maxn],xxxxx;

inline void print(node g[],int pre[],int i,int end)
{
    if (i==end) return;
    if (pre[i]==0)
    {
        if (f[a[i]][0]<f[a[i]][1]) printTree(a[i],1);
        else printTree(a[i],0);
        print(g,pre,i-1,end);
    }else
    {
        printTree(a[i],0);
        printTree(a[i-1],0);
        ans.PB(MP(a[i],a[i-1]));
        print(g,pre,i-2,end);
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",&next[i],&sex[i]);
        ++d[next[i]];
    }
    
    for (int i=1;i<=n;++i)
    {
        if (d[i]==0) q.push(i);
        f[i][0]=f[i][1]=node(0,0);
    }

    while (q.size())
    {
        int u=q.front();
        q.pop();
        int v=next[u];
        son[v].PB(u);
        --d[v];
        f[v][1]=f[v][1]+max(f[u][1],f[u][0]);
        if (f[v][1]<f[v][0]+f[u][0]+Cost(u,v))
        {
            f[v][1]=f[v][0]+f[u][0]+Cost(u,v);
            pre[v][1]=u;
        }
        f[v][0]=f[v][0]+max(f[u][1],f[u][0]);
        if (d[v]==0) q.push(v);
    }
    node best(0,0);
    int cc=0;
    for (int i=1;i<=n;++i)
    if (d[i])
    {
        int u=i,len=0;
        do
        {
            a[++len]=u;
            d[u]=0;
            //printf("%d %d %d\n",u,f[u][0].total,f[u][1].total);
            u=next[u];
        }while (u!=i);
        
        //a[1] not match a[len]
        g[0]=node(0,0);
        for (int i=1;i<=len;++i)
        {
            g[i]=node(-1,0);
            if (g[i]<g[i-1]+max(f[a[i]][0],f[a[i]][1]))
            {
                g[i]=g[i-1]+max(f[a[i]][0],f[a[i]][1]);
                h[i]=0;
            }
            if (i>=2 && g[i]<g[i-2]+f[a[i]][0]+f[a[i-1]][0]+Cost(a[i],a[i-1]))
            {
                g[i]=g[i-2]+f[a[i]][0]+f[a[i-1]][0]+Cost(a[i],a[i-1]);
                h[i]=1;
            }
            
            //printf("  %d %d\n",g[i].total,g[i].couple);
        }
        
        //a[1] match a[len]
        GG[1]=f[a[1]][0]+f[a[len]][0]+Cost(a[1],a[len]);
        for (int i=2;i<len;++i)
        {
            GG[i]=node(-1,0);
            if (GG[i]<GG[i-1]+max(f[a[i]][0],f[a[i]][1]))
            {
                GG[i]=GG[i-1]+max(f[a[i]][0],f[a[i]][1]);
                HH[i]=0;
            }
            if (i>2 && GG[i]<GG[i-2]+f[a[i]][0]+f[a[i-1]][0]+Cost(a[i],a[i-1]))
            {
                GG[i]=GG[i-2]+f[a[i]][0]+f[a[i-1]][0]+Cost(a[i],a[i-1]);
                HH[i]=1;
            }
        }
        if (g[len]<GG[len-1])
        {
            //puts("hi");
            best=best+GG[len-1];
            ans.PB(MP(a[1],a[len]));
            printTree(a[1],0);
            printTree(a[len],0);
            print(GG,HH,len-1,1);
        }else
        {
            //puts("hello");
            best=best+g[len];
            print(g,h,len,0);
        }
        
        if (ans.size()!=best.total)
        {
            printf("%d\n",++cc);
            printf("%d\n",len);
            for (int i=1;i<=len;++i)
                printf("    %d\n",a[i]);
            //while (1);
        }
    }
    
    int cnt=0;
    for (int i=0;i<ans.size();++i)
        cnt+=sex[ans[i].first]!=sex[ans[i].second];
    
    printf("%d %d\n",best.total,best.couple);
    
    //if (ans.size()!=best.total) while (1);
    //if (cnt!=best.couple) {vector<int> a;printf("%d\n",a[0]);}
    for (int i=0;i<ans.size();++i)
        printf("%d %d\n",ans[i].first,ans[i].second);
    
    return 0;
}