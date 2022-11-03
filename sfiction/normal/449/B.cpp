/*
ID: Sfiction
OJ: CF
PROB: 449B
*/
#include <cstdio>
#include <cstring>

const int MAXN=100000+10,MAXP=300000+10;
const long long INF=1LL<<60;

struct heap{
    int size;
    long long dis[MAXN];//the distance of node_id[i]
    int node_id[MAXN];//which node the distance dis[i] record
    int heap_id[MAXN];//where the node i's distance is in heap

    inline int parent(int i){
        return i>>1;
    }
    inline int left(int i){
        return i<<1;
    }
    inline int right(int i){
        return (i<<1)|1;
    }
    void swap(int i,int j){
        long long temp;
        int temp1;
        temp=dis[i];
        dis[i]=dis[j];
        dis[j]=temp;

        heap_id[node_id[i]]=j;
        heap_id[node_id[j]]=i;

        temp1=node_id[i];
        node_id[i]=node_id[j];
        node_id[j]=temp1;
    }
    void up(int i){
        int p=parent(i);
        while (p&&dis[p]>dis[i]){
            swap(p,i);
            i=p;
            p=parent(i);
        }
    }
    void down(int i){
        int l,r;
        int min;
        while (i<size){
            l=left(i);
            r=right(i);
            if (l<=size&&dis[l]<dis[i])
                min=l;
            else
                min=i;
            if (r<=size&&dis[r]<dis[min])
                min=r;
            if (min==i)
                break;
            else{
                swap(min,i);
                i=min;
            }
        }
    }
    void pop(){
        dis[1]=dis[size];
        heap_id[node_id[size]]=1;
        node_id[1]=node_id[size];
        --size;
        down(1);
    }
    void build(){
        int i;
        for (i=size>>1;i;--i)
            down(i);
    }
};

struct edge{
    int v;
    long long w;
    edge *nex;
};

edge* node[MAXN];
edge E[MAXP<<1];

int n,k;

int vis[MAXN];
bool used[MAXN];
heap f;

void Init(){
    int i,m;
    int u,v;
    long long w;
    int t=0;
    scanf("%d%d%d",&n,&m,&k);
    for (i=0;i<m;++i){
        scanf("%d%d%I64d",&u,&v,&w);
        E[t].v=v;
        E[t].w=w;
        E[t].nex=node[u];
        node[u]=&E[t];
        ++t;
        E[t].v=u;
        E[t].w=w;
        E[t].nex=node[v];
        node[v]=&E[t];
        ++t;
    }
}

void Dijkstra(){
    int i;
    edge *j;
    int p,q;
    int v;
    long long dist,w;

    memset(vis,0,sizeof(vis));
    f.size=n;
    for (i=1;i<=n;++i){
        used[i]=false;
        f.dis[i]=INF;
        f.heap_id[i]=i;
        f.node_id[i]=i;
    }

    for (i=1;i<=k;++i){
        scanf("%d%I64d",&v,&w);
        if (f.dis[v]>w){
            f.dis[v]=w;
            used[v]=true;
        }
    }

    f.dis[1]=0;
    f.build();

    for (i=0;i<n;++i){
        p=f.node_id[1];
        dist=f.dis[1];
        vis[p]=1;
        f.pop();

        for (j=node[p];j!=NULL;j=j->nex){
            q=j->v;
            if (!vis[q]){
                if (f.dis[f.heap_id[q]]>=dist+(j->w)){
                    f.dis[f.heap_id[q]]=dist+(j->w);
                    used[q]=false;
                    f.up(f.heap_id[q]);
                }
            }
        }
    }

    int cnt=0;
    for (i=1;i<=n;++i)
        if (used[i])
            ++cnt;
    printf("%d",k-cnt);
}

int main(){
    Init();
    Dijkstra();
    return 0;
}