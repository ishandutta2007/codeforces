#include <iostream>
using namespace std;
typedef long long LL;
const LL INF = -1e18;
const int N = 100000 + 10;
LL mn[N<<2],lz[N<<2],sum[N<<2];
int n;LL a[N],k[N],s[N];
void pushdown(int rt,int l,int r) {
    int mid=(l+r)>>1;
    if(lz[rt]!=INF) {
        lz[rt<<1]=max(lz[rt<<1], lz[rt]);
        lz[rt<<1|1]=max(lz[rt<<1|1], lz[rt]);
        sum[rt<<1]=(mid-l+1) * lz[rt];

        mn[rt<<1]=max(mn[rt<<1], lz[rt]);
        mn[rt<<1|1]=max(mn[rt<<1|1], lz[rt]);
        sum[rt<<1|1] = (r-mid) * lz[rt];
        lz[rt] = INF;
    }
}
void build(int l,int r,int rt) {
    mn[rt]=lz[rt]=INF;
    if(l==r) {
        mn[rt]=a[l]-k[l-1]; sum[rt]=mn[rt];
        //printf("%d %lld\n", l, mn[rt]);
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    mn[rt]=max(mn[rt<<1],mn[rt<<1|1]);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void update(int l,int r,int rt,int L,int R,LL x) {
    if(L<=l&&r<=R){
        lz[rt]=x; mn[rt]=x; sum[rt]=(r-l+1)*x; return;
    }
    int mid=(l+r)>>1; pushdown(rt,l,r);
    if(L<=mid) update(l,mid,rt<<1,L,R,x);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);
    mn[rt]=max(mn[rt<<1],mn[rt<<1|1]);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
LL query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)return mn[rt];
    pushdown(rt,l,r); int mid=(l+r)>>1; LL ans=INF;
    if(L<=mid) ans=max(ans,query(l,mid,rt<<1,L,R));
    if(R>mid) ans=max(ans,query(mid+1,r,rt<<1|1,L,R));
    return ans;
}
LL queryS(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R){
        return sum[rt];
    }
    pushdown(rt,l,r); int mid=(l+r)>>1; LL ans=0;
    if(L<=mid) ans=ans+queryS(l,mid,rt<<1,L,R);
    if(R>mid) ans=ans+queryS(mid+1,r,rt<<1|1,L,R);
    return ans;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<n;i++) {
        scanf("%lld",&k[i]); k[i] += k[i-1]; s[i]=s[i-1]+k[i];
    }
    int q; scanf("%d",&q);
    build(1,n,1);
    while(q--) {
        char op[2]; int l,r;
        scanf("%s%d%d",op,&l,&r);
        if(op[0] == 's') {
            printf("%lld\n", queryS(1,n,1,l,r) + s[r-1] - (l>=2?s[l-2]:0));
        } else {
            int lef=l+1,rig=n+1;
            LL tmp = query(1,n,1,l,l);
            update(1,n,1,l,l,tmp+r);
            if (l==n || query(1,n,1,l+1,l+1) >= tmp+r) {}
            else {
                while(rig-lef>1) {
                    int mid=(lef+rig)>>1;
                    if(query(1,n,1,l+1,mid) < tmp+r) {
                        lef = mid;
                    } else {
                        rig = mid;
                    }
                }
                update(1,n,1, l+1,lef,tmp+r);
            }
        }
    }
}