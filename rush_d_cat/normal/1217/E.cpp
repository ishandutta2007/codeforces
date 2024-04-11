#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL inf = 1e12;
int n,m,a[N];
struct Nod {
    LL m1[12],m2[12];
    Nod operator+(const Nod&o)const{
        Nod ans;
        for(int i=0;i<10;i++){
            ans.m1[i] = min(m1[i], o.m1[i]);
            if(m1[i] < o.m1[i]) {
                ans.m2[i] = min(m2[i], o.m1[i]);
            } else {
                ans.m2[i] = min(m1[i], o.m2[i]);
            }
        }
        return ans;
    }
} nod[N<<2];
void update(int l,int r,int rt,int pos,int x){
    if(l==r) {
        for(int i=0;i<10;i++) nod[rt].m1[i]=nod[rt].m2[i]=inf;
        int tmp=x,bit=0;
        while(tmp) {
            if(tmp%10) {
                nod[rt].m1[bit]=x;
            }
            tmp/=10; bit++;
        }
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos,x);
    else update(mid+1,r,rt<<1|1,pos,x);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
Nod query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) return nod[rt];
    int mid=(l+r)>>1;
    if(L >mid) return query(mid+1,r,rt<<1|1,L,R);
    if(R<=mid) return query(l,mid,rt<<1,L,R);
    return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);
}
int main() {
    for(int i=0;i<N<<2;i++) {
        for(int j=0;j<10;j++) nod[i].m1[j]=nod[i].m2[j]=inf;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]); update(1,n,1,i,a[i]);
    }
    while(m--) {
        int op,l,r; scanf("%d%d%d",&op,&l,&r);
        if(op==1) {
            update(1,n,1,l,r);
        } else {
            Nod nod = query(1,n,1,l,r);
            LL ans = inf;
            for(int i=0;i<10;i++) {
                //printf("i=%d, (%lld,%lld)\n", i,nod.m1[i],nod.m2[i]);
                ans=min(ans,nod.m1[i] + nod.m2[i]);
            }
            if(ans>1e10) ans=-1;
            printf("%lld\n", ans);
        }
    }
}