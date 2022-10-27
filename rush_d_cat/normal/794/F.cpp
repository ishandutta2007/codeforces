#include <iostream>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int n,q,a[N];
struct Nod {
    LL sum[10]; int nxt[10];
    void upd(int *nex) {
        LL tmp[10]={0};
        for(int i=0;i<10;i++)
            tmp[nex[i]] += sum[i];
        for(int i=0;i<10;i++)
            sum[i] = tmp[i], nxt[i]=nex[nxt[i]];
    }
    void prt() {
        printf("###\n");
        for(int i=0;i<10;i++)printf("%d ", sum[i]); printf("\n");
        for(int i=0;i<10;i++)printf("%d ", nxt[i]); printf("\n");
    }
} nod[N<<2];
void pushup(int rt) {
    for(int i=0;i<10;i++) nod[rt].sum[i]=nod[rt<<1].sum[i] + nod[rt<<1|1].sum[i];
}
void pushdown(int rt) {
    nod[rt<<1].upd(nod[rt].nxt);
    nod[rt<<1|1].upd(nod[rt].nxt);
    for(int i=0;i<10;i++)nod[rt].nxt[i]=i;
}
void build(int l,int r,int rt) {
    for(int i=0;i<10;i++)nod[rt].nxt[i]=i,nod[rt].sum[i]=0;
    if(l==r) {
        LL pw=1, tmp=a[l];
        while(tmp) {
            nod[rt].sum[tmp%10] += pw; pw *= 10, tmp /= 10;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void update(int l,int r,int rt,int L,int R,int x,int y){
    if(L<=l&&r<=R) {
        for(int i=0;i<10;i++) {
            if(nod[rt].nxt[i] == x) {
                nod[rt].nxt[i] = y;
                nod[rt].sum[y] += nod[rt].sum[x]; nod[rt].sum[x] = 0;
            }
        }
        return;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,rt<<1,L,R,x,y);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,x,y);
    pushup(rt);
}
LL query(int l,int r,int rt,int L,int R){
    pushdown(rt);
    if(L<=l&&r<=R) {
        LL s=0;
        for(int i=0;i<10;i++)s+=i*nod[rt].sum[i];
        return s;
    }
    int mid=(l+r)>>1; LL ans=0;
    if(L<=mid) ans += query(l,mid,rt<<1,L,R);
    if(R >mid) ans += query(mid+1,r,rt<<1|1,L,R);
    return ans;
}
int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=q;i++){
        int op,l,r,x,y; scanf("%d",&op);
        if(op==1) {
            scanf("%d%d%d%d",&l,&r,&x,&y);
            if(x==y)continue;
            update(1,n,1,l,r,x,y);
        } else {
            scanf("%d%d",&l,&r);
            printf("%lld\n", query(1,n,1,l,r));
        }
    }
}