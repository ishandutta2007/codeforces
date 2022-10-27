#include <iostream>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
LL mn[N<<2], lz[N<<2];
int n,p[N],a[N],pos[N];
void pushdown(int rt){
    if(lz[rt]){
        lz[rt<<1]+=lz[rt];
        mn[rt<<1]+=lz[rt];
        lz[rt<<1|1]+=lz[rt];
        mn[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
}
void update(int l,int r,int rt,int L,int R,int x){
    if(L<=l&&r<=R){
        mn[rt]+=x; lz[rt]+=x; return;
    }
    int mid=(l+r)>>1; pushdown(rt);
    if(L<=mid) update(l,mid,rt<<1,L,R,x);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
void prt(int l,int r,int rt){
    if(l==r){
        printf("%d ", mn[l]); return;
    }
    int mid=(l+r)>>1; pushdown(rt);
    prt(l,mid,rt<<1); prt(mid+1,r,rt<<1|1);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]),pos[p[i]]=i;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=min(a[1],a[n]);
    //printf("$ %d\n", ans);
    for(int i=1;i<=n;i++){
        update(1,n-1,1,i,n,a[i]);
    }
    //prt(1,n-1,1); printf("\n");
    for(int i=1;i<=n;i++) {
        int p=pos[i];
        if(p>=2) update(1,n-1,1,1,p-1,a[p]);
        update(1,n-1,1,p,n,-a[p]);
        //printf("i=%d: ", i); prt(1,n-1,1); printf("\n");
        ans=min((LL)ans,mn[1]);
    }
    cout<<ans<<endl;
}