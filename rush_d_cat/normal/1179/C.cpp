#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 1000000 + 10;

int n,m,a[N],b[N];
int mx[N<<2],lz[N<<2];
void pushdown(int rt){
    if(lz[rt]){
        mx[rt<<1]+=lz[rt]; lz[rt<<1]+=lz[rt];
        mx[rt<<1|1]+=lz[rt]; lz[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
}
void update(int l,int r,int rt,int L,int R,int x){
    if(L<=l&&r<=R){
        //printf("upd %d %d %d\n", l,r,x);
        mx[rt] += x; lz[rt] += x; return;
    }
    int mid=(l+r)>>1; pushdown(rt);
    if (L<=mid) update(l,mid,rt<<1,L,R,x);
    if (R>mid) update(mid+1,r,rt<<1|1,L,R,x);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
int query(int l,int r,int rt){
    if(l==r) return l;
    int mid=(l+r)>>1; pushdown(rt);
    //printf("l=%d, r=%d, mx=%d\n", l,r,mx[rt]);
    if(mx[rt<<1|1]>0) return query(mid+1,r,rt<<1|1);
    return query(l,mid,rt<<1);  
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); update(1,N-1,1,1,a[i],1);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]); update(1,N-1,1,1,b[i],-1);
    }
    int q; scanf("%d",&q);
    while(q--) {
        int op,pos,x; scanf("%d%d%d",&op,&pos,&x);
        if(op==1) {
            update(1,N-1,1,1,a[pos],-1); a[pos]=x; update(1,N-1,1,1,a[pos],+1);
        } else {
            update(1,N-1,1,1,b[pos],+1); b[pos]=x; update(1,N-1,1,1,b[pos],-1);
        }
        if(mx[1] <= 0) printf("-1\n");
        else printf("%d\n", query(1,N-1,1));
    }
}