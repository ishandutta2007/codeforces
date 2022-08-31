#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=310000;
const LL inf=1ll<<60;
struct Set{
    multiset<LL> a;
    multiset<pair<int,LL> >b; 
    LL w;
    inline void init(){
        a.clear();b.clear();w=0;
    }
    inline void insert(int id,LL x){
        a.insert(x-w);
        b.insert(pair<int,LL>(id,x-w));
    }
    inline void add(LL x){w+=x;}
    inline LL min(){
        if(!a.size())return inf;
        return (*(a.begin()))+w;
    }
    inline void del(int id){
        set<pair<int,LL> >::iterator w2=b.lower_bound(pair<int,LL>(id,-inf));
        assert(w2!=b.end());
        pair<int,LL>ww=*w2;
        a.erase(a.find(ww.se));
        b.erase(b.find(ww));
    }
    inline int size(){return a.size();}
    inline bool Get(pair<int,LL> &x){
        if(!b.size())return 0;
        x=*b.begin();
        b.erase(b.begin());
        x.se+=w;
        return 1;
    }
};
int head[N],np[N<<1],p[N<<1],tot;
int dep[N],fa[N];
int n,m;
vector<pii>tail[N],top[N];
void dfs(int x){
    for(int u=head[x];u;u=np[u])if(p[u]^fa[x]){
        fa[p[u]]=x;dep[p[u]]=dep[x]+1;dfs(p[u]);
    }
}
LL f[N];
Set val[N];
int id[N];
void dp(int x){
    LL sum=0;
    id[x]=x;
    for(int u=head[x];u;u=np[u])if(p[u]^fa[x]){
        dp(p[u]);
        sum+=f[p[u]];
    }
    val[x].init();
    rep(i,0,tail[x].size()-1){
        val[x].insert(tail[x][i].fi,tail[x][i].se+sum);
    }
    for(int u=head[x];u;u=np[u])if(p[u]^fa[x]){
        int y=id[p[u]];
        val[y].add(sum-f[p[u]]);
        if(val[y].size()>val[id[x]].size())swap(y,id[x]);
        pair<int,LL>gt;
        while(val[y].Get(gt)){
            val[id[x]].insert(gt.fi,gt.se);
        }
    }
    if(x!=1){
        rep(i,0,top[x].size()-1){
            val[id[x]].del(top[x][i].fi);
        }
    }
    f[x]=val[id[x]].min();
    if(f[x]>inf-100){
        puts("-1");
        exit(0);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    if(n==1){
        puts("0");
        return 0;
    }
    rep(i,1,n-1){
        int a,b;scanf("%d%d",&a,&b);
        ++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;
        ++tot;p[tot]=a;np[tot]=head[b];head[b]=tot;
    }
    dfs(1);
    rep(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        if(dep[u]>dep[v])swap(u,v);
        top[u].push_back(pii(i,w));
        tail[v].push_back(pii(i,w));
    }
    dp(1);
    if(f[1]>inf-1000)f[1]=-1;
    printf("%I64d\n",f[1]);
    return 0;
}