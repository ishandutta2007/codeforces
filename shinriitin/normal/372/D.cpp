#include <set>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define g() getchar()
template<class Q>void Scan(Q&x){
    char c;int f=1;
    while(c=g(),c<48||c>57)if(c=='-')f=-1;
    for(x=0;c>47&&c<58;c=g())x=10*x+c-48;
    x*=f;
}

#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
typedef double db;

const int MAXN=1e5+5;

struct edge{
    int t,n;
    edge(int t=0,int n=0):t(t),n(n){}
}e[MAXN<<1];
int head[MAXN],tot;
inline void AddEdge(int s,int t){
    e[++tot]=edge(t,head[s]),head[s]=tot;
    e[++tot]=edge(s,head[t]),head[t]=tot;
}

int n,k;

int dep[MAXN];

int dfn[MAXN],cnt;

int p[MAXN][20];

void dfs(int x){
    dfn[x]=++cnt;
    for(int i=0;p[x][i];++i)
        p[x][i+1]=p[p[x][i]][i];
    for(int i=head[x],y;i;i=e[i].n)
        if((y=e[i].t)!=*p[x]){
            *p[y]=x;
            dep[y]=dep[x]+1;
            dfs(y);
        }
}

typedef pair<int,int>pr;
set<pr>s;
typedef set<pr>::iterator It;

int ans;

inline int swim(int x,int h){
    for(int i=0;h;++i,h>>=1)
        if(h&1)x=p[x][i];
    return x;
}

inline int lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);
    y=swim(y,dep[y]-dep[x]); 
    for(int i=19;~i;--i)
        if(p[x][i]!=p[y][i]){
            x=p[x][i];
            y=p[y][i];
        }
    return x==y?x:*p[x];
}

inline int dis(int x,int y){
    return dep[x]+dep[y]-dep[lca(x,y)]*2;
}

inline void insert(int x){
    It it=s.insert(pr(dfn[x],x)).fi;
    if(s.size()==1)return;
    It prev,next;
    It head=s.begin(),tail=--s.end();
    if(it==head)prev=tail;
    else prev=--it,++it;
    if(it==tail)next=head;
    else next=++it,--it;
    ans-=dis(prev->se,next->se);
    ans+=dis(prev->se,x);
    ans+=dis(x,next->se); 
}

inline void remove(int x){
    It it=s.find(pr(dfn[x],x));
    if(s.size()==1){
        s.erase(it);
        return;
    }
    It prev,next;
    It head=s.begin(),tail=--s.end();
    if(it==head)prev=tail;
    else prev=--it,++it;
    if(it==tail)next=head;
    else next=++it,--it;
    ans+=dis(prev->se,next->se);
    ans-=dis(prev->se,x);
    ans-=dis(x,next->se);
    s.erase(it); 
}

inline void Init(){
    Scan(n),Scan(k);
    rep(i,1,n){
        int x,y;
        Scan(x),Scan(y);
        AddEdge(x,y);
    }
    dfs(1);
}

int ans1;

inline void Solve(){
    int l=1;
    rep(r,1,n+1){
        insert(r);
        while((ans>>1)>=k)remove(l++);
        ans1=max(ans1,r-l+1);
    }
    printf("%d\n",ans1);
}

int main(){
    Init(); Solve(); return 0;
}