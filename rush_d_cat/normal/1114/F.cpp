#include <iostream>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

typedef long long LL;
const int N=600000+10;
const int MOD=1e9+7;

int n,q,a[N];
bitset<302> B[302],zero;

struct Nod{
    bitset<302> has, haslz;
    LL m, lz;

    Nod operator + (const Nod&o) const{
        Nod ans;
        ans.has = has | o.has, ans.haslz = zero;
        ans.m = m * o.m % MOD, ans.lz = 1;
        return ans;
    }
} nod[N<<2];

void build(int l,int r,int rt){
    nod[rt].lz=1; nod[rt].haslz.reset();
    if(l==r) {
        nod[rt].m=a[l];
        nod[rt].has=B[a[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);

    nod[rt].has = nod[rt<<1].has | nod[rt<<1|1].has;
    nod[rt].m = nod[rt<<1].m * nod[rt<<1|1].m % MOD;
}

unordered_map<int,int> pw[302];
int mpow(int x,int k) {
    //if(pw[x][k]) return pw[x][k];
    if(k==0) return 1;
    int t=mpow(x,k/2);
    if(k%2==0) return 1LL*t*t%MOD;
    return 1LL*t*t%MOD*x%MOD;
}

void gao(int rt,int l,int r,int x,bitset<302> b) {
    nod[rt].has |= b; 
    nod[rt].haslz |= b;
    nod[rt].m = nod[rt].m * mpow(x,r-l+1) % MOD;
    nod[rt].lz = nod[rt].lz * x % MOD;
}

void pushdown(int rt,int l,int r) {
    if(nod[rt].lz != 1 || nod[rt].haslz != zero) {
        int mid=(l+r)>>1;
        gao(rt<<1,l,mid,nod[rt].lz,nod[rt].haslz);
        gao(rt<<1|1,mid+1,r,nod[rt].lz,nod[rt].haslz);
        nod[rt].lz=1, nod[rt].haslz = zero;
    }
}

void update(int l,int r,int rt,int L,int R,int x) {
    if(L<=l&&r<=R) {
        gao(rt,l,r,x,B[x]); return;
    }
    pushdown(rt,l,r); int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,rt<<1,L,R,x);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);

    nod[rt].has = nod[rt<<1].has | nod[rt<<1|1].has;
    nod[rt].m = nod[rt<<1].m * nod[rt<<1|1].m % MOD;
}

Nod query(int l,int r,int rt,int L,int R) {
    //printf("l=%d, r=%d\n", l,r);
    if(L<=l&&r<=R) {
        return nod[rt];
    }
    pushdown(rt,l,r); int mid=(l+r)>>1;
    if(R<=mid) return query(l,mid,rt<<1,L,R);
    if(L >mid) return query(mid+1,r,rt<<1|1,L,R);
    return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);
}

LL inv[302];
int main() {
    inv[1]=1;
    for(int i=2;i<302;i++){
        inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    }
    for(int x=1;x<=300;x++) {
        int t=x;
        for(int i=2;i*i<=t;i++){
            if(t%i==0){
                B[x][i]=1;
                while(t%i==0) t/=i; 
            }
        }
        if(t>1) B[x][t]=1;
    }
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int t=1;
    while(t<n) t*=2; n=t;
    build(1,n,1);
    while(q--) {
        char s[10]; int l,r,x; scanf("%s",s);
        if(s[0]=='M') {
            scanf("%d%d%d",&l,&r,&x);
            update(1,n,1,l,r,x);
        } else {
            scanf("%d%d",&l,&r);
            Nod ans = query(1,n,1,l,r);
            LL res = ans.m;
            //printf("# %lld\n", res);
            for(int i=1;i<=300;i++) {
                if(ans.has[i]) {
                    res = res * (i-1) % MOD * inv[i] % MOD;
                }
            }
            printf("%lld\n", res);
        }
    }
}