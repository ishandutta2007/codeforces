#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double a,double b){x=a;y=b;}
    inline double norm(){return sqrt(sqr(x)+sqr(y));}
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
//==============================================================================================

const int maxn  =   5005;

int size[maxn],father[maxn],n;
VI adj[maxn];
bool ans[maxn],f[maxn];

inline void dfs(int u,int fa)
{
    father[u]=fa;
    size[u]=1;
    for (int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if (v==fa) continue;
        dfs(v,u);
        size[u]+=size[v];
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    int root=rand()%n;
    dfs(root,-1);
    
    memset(ans,false,sizeof(ans));
    for (int i=0;i<n;++i){
        VI a;
        if (i!=root) a.push_back(size[root]-size[i]);
        for (int j=0;j<adj[i].size();++j){
            int v=adj[i][j];
            if (v!=father[i]){
                a.push_back(size[v]);
            }
        }
        int s=0;
        memset(f,false,sizeof(f));
        f[0]=true;

        for (int j=0;j<a.size();++j){
            s+=a[j];
            for (int k=s;k>=a[j];--k)
                f[k]|=f[k-a[j]];
        }
        for (int j=1;j<s;++j)
            ans[j]|=f[j];
    }
    
    int cnt=0;
    for (int i=1;i<n-1;++i) cnt+=ans[i];
    printf("%d\n",cnt);
    for (int i=1;i<n-1;++i)
    if (ans[i]) printf("%d %d\n",i,n-1-i);
    
    if (cnt==0){
        VI a;
        printf("%d\n",a[0]);
    }
    
    return 0;
}