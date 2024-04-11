/*
ID: Sfiction
OJ: CF
PROB: 463E
*/
#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=100000+10;
const int MAXA=2000000,MAXP=250;

int plen,prime[MAXP];

struct node;

struct edge{
    int v;
    edge *nex;

    edge(){
        v=0;
        nex=NULL;
    }

    void AddEdge(int v){
        edge *t=new edge;
        t->v=v;
        t->nex=nex;
        nex=t;
    }

    void DeleteEdge(){
        edge *t=nex->nex;
        delete nex;
        nex=t;
    }
};

struct node{
    int num,ans;
    int len,div[10];
    int vis;
    edge sta;

    node(){
        ans=-1;
        num=len=0;
        vis=false;
    }

    void division(){
        int t=num;
        len=0;
        for (int i=0;i<plen && prime[i]*prime[i]<=t;++i)
            if (t%prime[i]==0){
                div[len++]=prime[i];
                while (t%prime[i]==0)
                    t/=prime[i];
            }
        if (t>1)
            div[len++]=t;
    }

    void AddEdge(int v){
        sta.AddEdge(v);
    }

    void DeleteEdge(){
        sta.DeleteEdge();
    }
};

int n,q;
int time;
node f[MAXN];

edge flag[MAXA+1];

void GetPrime(){
    int t=sqrt(MAXA);
    for (int i=2;i<=t;++i){
        if (!flag[i].v)
            prime[plen++]=i;
        for (int j=0;j<=plen && prime[j]*i<=t;++j){
            flag[prime[j]*i].v=1;
            if (i%prime[j]==0)
                break;
        }
    }
}

void Fresh(int now){
    int j;

    f[now].vis=++time;

    f[now].ans=-1;
    for (int i=0;i<f[now].len;++i){
        j=f[now].div[i];
        if (flag[j].nex!=NULL){
            if (f[now].ans==-1 || f[f[now].ans].vis<(f[(flag[j].nex)->v].vis))
                f[now].ans=(flag[j].nex)->v;
        }
        flag[j].AddEdge(now);
    }

    for (edge *i=(f[now].sta).nex;i;i=i->nex)
        if (!f[i->v].vis)
            Fresh(i->v);

    for (int i=0;i<f[now].len;++i)
        flag[f[now].div[i]].DeleteEdge();
    f[now].vis=0;
}

void Init(){
    int u,v;

    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;++i){
        scanf("%d",&f[i].num);
        f[i].division();
    }
    for (int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        f[u].AddEdge(v);
        f[v].AddEdge(u);
    }
    time=0;
    Fresh(1);
}

int main(){
    int type,a,b;

    GetPrime();
    Init();

    while (q--){
        scanf("%d%d",&type,&a);
        if (type==1)
            printf("%d\n",f[a].ans);
        else{
            scanf("%d",&b);
            f[a].num=b;
            f[a].division();
            time=0;
            Fresh(1);
        }
    }
    return 0;
}