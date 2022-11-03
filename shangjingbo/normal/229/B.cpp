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

const int maxn  =   100005;
const int maxm  =   100005*2;

int head[maxn],vtx[maxm],next[maxm],cost[maxm],tot;
int n,m;
map<int,int> forbid[maxn];

long long dist[maxn];
bool vis[maxn];

inline void add(int a,int b,int c)
{
    vtx[tot]=b;
    next[tot]=head[a];
    cost[tot]=c;
    head[a]=tot++;
}

inline bool update(long long &a,long long b)
{
    if (a==-1 || a>b){
        a=b;
        return true;
    }
    return false;
}

inline void spfa()
{
    queue<int> q;
    q.push(1);
    memset(dist,-1,sizeof(dist));
    memset(vis,false,sizeof(vis));
    dist[1]=0;
    while (q.size()){
        int u=q.front();
        vis[u]=false;
        q.pop();
        
        int st=dist[u];
        if (forbid[u].count(st)) st=forbid[u][st];
        for (int p=head[u];p;p=next[p]){
            if (update(dist[vtx[p]],st+cost[p])){
                if (!vis[vtx[p]]){
                    q.push(vtx[p]);
                    vis[vtx[p]]=true;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    tot=2;
    memset(head,0,sizeof(head));
    for (int i=0;i<m;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    
    for (int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        forbid[i].clear();
        for (int j=0;j<x;++j){
            int t;
            scanf("%d",&t);
            forbid[i][t]=t+1;
        }
        for (map<int,int>::iterator it=forbid[i].begin(),ed;it!=forbid[i].end();){
            ed=it;
            int last=it->first-1;
            while (ed!=forbid[i].end() && ed->first==last+1){
                ++last;
                ++ed;
            }
            while (it!=ed){
                it->second=last+1;
                ++it;
            }
        }
    }
    
    spfa();
    
    printf("%I64d\n",dist[n]);  
    return 0;
}