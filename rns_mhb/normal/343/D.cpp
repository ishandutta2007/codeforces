#include <stdio.h>
#include <memory.h>
using namespace std;
#define N 2000011
#define lef(id) (id<<1)
#define rig(id) (id<<1|1)
struct tree {
    int val,sum;
    bool down;
} tr[N];
void push_up(int st,int en,int id) {
    tr[id].sum=tr[lef(id)].sum+tr[rig(id)].sum;
}
void push_down(int st,int en,int id) {
    if (tr[id].down) return;
    tr[lef(id)].down=tr[rig(id)].down=0;
    tr[lef(id)].val=tr[rig(id)].val=tr[id].val;
    int mi=(st+en)/2;
    tr[lef(id)].sum=tr[lef(id)].val*(mi-st+1);
    tr[rig(id)].sum=tr[rig(id)].val*(en-mi);
    tr[id].down=1;
}
void put(int s,int e,int val,int st,int en,int id) {
    if (s<=st && en<=e) {
        tr[id].val=val;
        tr[id].sum=val*(en-st+1);
        tr[id].down=0;
        return;
    }
    push_down(st,en,id);
    int mi=(st+en)/2;
    if (mi>=s) put(s,e,val,st,mi,lef(id));
    if (mi+1<=e) put(s,e,val,mi+1,en,rig(id));
    push_up(st,en,id);
}
int get(int s,int e,int st,int en,int id) {
    if (s<=st && en<=e) return tr[id].sum;
    push_down(st,en,id);
    int mi=(st+en)/2,su=0;
    if (mi>=s) su+=get(s,e,st,mi,lef(id));
    if (mi+1<=e) su+=get(s,e,mi+1,en,rig(id));
    return su;
}
void make_tree(int st,int en,int id) {
    tr[id].val=tr[id].sum=tr[id].down=0;
    if (st==en) return;
    int mi=(st+en)/2;
    make_tree(st,mi,lef(id));
    make_tree(mi+1,en,rig(id));
}
int cur,head[N],next[N],to[N];
int dt[N],ft[N],par[N];
void dfs(int r) {
    dt[r]=++cur;
    for (int i=head[r];i!=-1;i=next[i]) {if (dt[to[i]]==-1) par[to[i]]=r,dfs(to[i]);}
    ft[r]=cur;
}
int main() {
    //freopen("d.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,a,b;
    while (scanf("%d",&n)>0 && n) {
        memset(head,-1,sizeof(head));
        cur=0;
        for (int i=1;i<n;i++) {
            scanf("%d%d",&a,&b);
            ++cur;to[cur]=b;next[cur]=head[a];head[a]=cur;
            ++cur;to[cur]=a;next[cur]=head[b];head[b]=cur;
        }
        memset(dt,-1,sizeof(dt));
        cur=0;dfs(1);
        make_tree(1,n,1);
        for (scanf("%d",&m);m--;) {
            scanf("%d%d",&a,&b);
            if (a==1) {
                if (get(dt[b],ft[b],1,n,1)!=ft[b]-dt[b]+1 && b!=1) put(dt[par[b]],dt[par[b]],0,1,n,1);
                put(dt[b],ft[b],1,1,n,1);
            }
            else if (a==2) put(dt[b],dt[b],0,1,n,1);
            else printf("%d\n",get(dt[b],ft[b],1,n,1)==ft[b]-dt[b]+1);
        }
    }
}