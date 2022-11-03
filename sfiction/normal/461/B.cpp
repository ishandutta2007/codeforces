/*
ID: Sfiction
OJ: CF
PROB: 461B
*/
#include <cstdio>

const int MAXN=100000+10;
const long long MOD=1000000007;

struct edge;

struct node{
    char color;
    long long in,ex;
    edge *nex;
};

struct edge{
    node *v;
    edge *nex;
};

int n;
node f[MAXN];

void Init(){
    int i,u;

    scanf("%d",&n);
    for (i=1;i<n;++i){
        edge *t=new edge;
        scanf("%d",&u);
        t->v=&f[i];
        t->nex=f[u].nex;
        f[u].nex=t;
    }
    for (i=0;i<n;++i){
        scanf("%d",&u);
        f[i].color=u;
    }
}

void Calc(node *now){
    now->in=0;
    now->ex=1;
    for (edge *i=now->nex;i;i=i->nex){
        node *j=i->v;
        Calc(j);
        now->in=(now->in*j->ex+now->ex*j->in)%MOD;
        now->ex=now->ex*j->ex%MOD;
    }
    if (now->color)
        now->in=now->ex;
    else
        now->ex=(now->ex+now->in)%MOD;
}

int main(){
    Init();
    Calc(&f[0]);
    printf("%I64d",f[0].in);
    return 0;
}