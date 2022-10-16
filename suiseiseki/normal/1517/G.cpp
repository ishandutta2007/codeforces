#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=1000;
const int Maxm=1000000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n;
struct Node{
    int x,y,w,id;
    friend bool operator <(Node a,Node b){
        return a.x<b.x;
    }
    Node(int _x=0,int _y=0,int _w=0,int _id=0){
        x=_x,y=_y,w=_w,id=_id;
    }
}a[Maxn+5];
int id[Maxn+5][2],id_tot;
int S,T;
struct Edge{
    int to,flow;
    ll cap,nxt;
}edge[Maxm<<1|5];
int head[Maxn<<1|5],tot;
void unuse_add_edge(int from,int to,ll cap){
    edge[++tot].to=to;
    edge[tot].cap=cap;
    edge[tot].flow=0;
    edge[tot].nxt=head[from];
    head[from]=tot;
}
void add_edge(int from,int to,ll cap){
    unuse_add_edge(from,to,cap);
    unuse_add_edge(to,from,0);
}
int qu[Maxn<<1|5],qu_f,qu_t;
int dep[Maxn<<1|5];
bool Dinic_bfs(){
    memset(dep,0,sizeof dep);
    dep[S]=1;
    qu_f=1,qu_t=0;
    qu[++qu_t]=S;
    while(qu_f<=qu_t){
        int u=qu[qu_f++];
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].to;
            if(dep[v]||edge[i].flow==edge[i].cap){
                continue;
            }
            dep[v]=dep[u]+1;
            qu[++qu_t]=v;
        }
    }
    return dep[T]>0;
}
ll Dinic_dfs(int u,ll flow){
    if(u==T||flow==0){
        return flow;
    }
    ll sum=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(dep[v]!=dep[u]+1||edge[i].flow==edge[i].cap){
            continue;
        }
        ll op=std::min(edge[i].cap-edge[i].flow,flow-sum),f;
        if((f=Dinic_dfs(v,op))){
            sum+=f;
            edge[i].flow+=f;
            edge[((i-1)^1)+1].flow-=f;
            if(sum==flow){
                break;
            }
        }
    }
    if(sum==0){
        dep[u]=0;
    }
    return sum;
}
ll Dinic(){
    ll ans=0;
    while(Dinic_bfs()){
        ans+=Dinic_dfs(S,Inf);
    }
    return ans;
}
std::map<int,std::map<int,int> > mp;
int main(){
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
        sum+=a[i].w;
        mp[a[i].x][a[i].y]=i;
    }
    for(int i=1;i<=n;i++){
        id[i][0]=++id_tot,id[i][1]=++id_tot;
        add_edge(id[i][0],id[i][1],a[i].w);
    }
    S=++id_tot,T=++id_tot;
    for(int i=1;i<=n;i++){
        if((a[i].x&1)&&(a[i].y&1)){
            add_edge(S,id[i][0],Inf);
            if(mp[a[i].x-1][a[i].y]){
                add_edge(id[i][1],id[mp[a[i].x-1][a[i].y]][0],Inf);
            }
            if(mp[a[i].x+1][a[i].y]){
                add_edge(id[i][1],id[mp[a[i].x+1][a[i].y]][0],Inf);
            }
        }
        else if(a[i].x&1){
            add_edge(id[i][1],T,Inf);
        }
        else if(a[i].y&1){
            if(mp[a[i].x][a[i].y-1]){
                add_edge(id[i][1],id[mp[a[i].x][a[i].y-1]][0],Inf);
            }
            if(mp[a[i].x][a[i].y+1]){
                add_edge(id[i][1],id[mp[a[i].x][a[i].y+1]][0],Inf);
            }
        }
        else{
            if(mp[a[i].x-1][a[i].y]){
                add_edge(id[i][1],id[mp[a[i].x-1][a[i].y]][0],Inf);
            }
            if(mp[a[i].x+1][a[i].y]){
                add_edge(id[i][1],id[mp[a[i].x+1][a[i].y]][0],Inf);
            }
        }
    }
    ll ans=Dinic();
    printf("%lld\n",sum-ans);
    return 0;
}