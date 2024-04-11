#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1000000 + 10;
vector<int> v;
void dfs(int dep,int now){
    v.push_back(now);
    if(dep==9) return;
    dfs(dep+1,now*10+4); 
    dfs(dep+1,now*10+7);
}
int n,m,a[N],mindis[N];
struct Nod{
    int mn,cnt,lz,val;
    Nod operator + (const Nod & o) const {
        Nod ans; ans.mn = min(mn,o.mn); ans.cnt=0;
        if(ans.mn==mn) ans.cnt+=cnt; if(ans.mn==o.mn)ans.cnt+=o.cnt; 
        ans.val=val, ans.lz=0; 
        return ans;
    }
} nod[N<<2];
void pushdown(int rt) {
    if(nod[rt].lz) {
        nod[rt<<1].lz += nod[rt].lz;
        nod[rt<<1|1].lz += nod[rt].lz;
        nod[rt<<1].mn -= nod[rt].lz, nod[rt<<1].val += nod[rt].lz;
        nod[rt<<1|1].mn -= nod[rt].lz, nod[rt<<1|1].val += nod[rt].lz;
        nod[rt].lz = 0;
    }
}
void build(int l,int r,int rt){
    nod[rt].lz=0;
    if(l==r) {
        nod[rt].cnt=1, nod[rt].mn=mindis[a[l]]; nod[rt].val=a[l]; return;
    }
    int mid=(l+r)>>1; 
    build(l,mid,rt<<1); 
    build(mid+1,r,rt<<1|1);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
void update(int l,int r,int rt,int L,int R,int sub) {
    nod[rt].val += sub;
    if(l==r) {
        if(nod[rt].mn>=sub) nod[rt].mn -= sub;
        else nod[rt].mn = mindis[nod[rt].val];
        return;
    }
    if(L<=l&&r<=R) {
        int mid=(l+r)>>1;
        if(nod[rt].mn >= sub) { nod[rt].lz += sub; nod[rt].mn -= sub; return;}
        pushdown(rt);
        update(l,mid,rt<<1,L,R,sub); update(mid+1,r,rt<<1|1,L,R,sub); 
        nod[rt]=nod[rt<<1]+nod[rt<<1|1];return;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,rt<<1,L,R,sub);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,sub);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
Nod query(int l,int r,int rt,int L,int R) {
    if(L<=l&&r<=R) return nod[rt];
    int mid=(l+r)>>1; pushdown(rt);
    if(L>mid) return query(mid+1,r,rt<<1|1,L,R);
    if(R<=mid)return query(l,mid,rt<<1,L,R);
    return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);
}
int main() {
    dfs(0,0); sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++) {
        if(v[i+1]>=1e5) break;
        for(int j=v[i]+1;j<=v[i+1];j++) mindis[j]=v[i+1]-j;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=m;i++) {
        char op[6]; int l,r,x;
        scanf("%s%d%d",op,&l,&r);
        if(op[0]=='c') {
            Nod ans = query(1,n,1,l,r); 
            printf("%d\n", ans.mn == 0 ? ans.cnt : 0);
        } else {
            scanf("%d",&x); update(1,n,1,l,r,x);
        }
    }
}