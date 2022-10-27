#include <iostream>
using namespace std;
const int N=500000+10;
struct Nod {
    double a,b;
    Nod operator + (const Nod & o) const {
        Nod ret;
        ret.a = a*o.a;
        ret.b = b+a*o.b;
        return ret;
    }
} nod[N];
void push_up(int rt) {
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
void build(int l,int r,int rt) {
    if(l==r){
        double x,y;
        scanf("%lf%lf",&x,&y);double p=x/y;
        nod[rt].a=nod[rt].b=(1-p)/p;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    push_up(rt);
}
void update(int l,int r,int rt,int pos,double x){
    if(l==r){
        nod[rt].a=nod[rt].b=(1-x)/x;
        return;
    }
    int mid=(l+r)>>1;
    if (pos <= mid)
        update(l,mid,rt<<1,pos,x);
    else
        update(mid+1,r,rt<<1|1,pos,x);
    push_up(rt);
}
Nod query(int l,int r,int rt,int L,int R) {
    if(L<=l&&r<=R){
        return nod[rt];
    }
    int mid=(l+r)>>1;
    if(mid >= L && !(mid < R))
        return query(l,mid,rt<<1,L,R);
    if(mid <  R && !(mid >=L))
        return query(mid+1,r,rt<<1|1,L,R); 
    return query(l,mid,rt<<1,L,R)+query(mid+1,r,rt<<1|1,L,R);
}
int n,q;
void prt() {
    for(int i=1;i<=n;i++) {
        printf("%.5f\n", query(1,n,1,i,i).a);
    }
}

int main() {
    scanf("%d%d",&n,&q);
    build(1,n,1); ///prt();
    while(q--) {
        int op,pos,l,r;
        scanf("%d",&op);
        if (op==1){
            scanf("%d %d %d",&pos,&l,&r);
            update(1,n,1,pos,1.0*l/r);
        }else{
            scanf("%d %d",&l,&r);
            double ans = 1.0 / (query(1,n,1,l,r).b+1);
            printf("%.5f\n", ans);
        }
    }
}