#include <iostream>
using namespace std;
const int N = 300000+10;
typedef long long LL;
int n,a[N]; LL ans=0;
struct Nod {
    int mn,cnt,lz;
    Nod operator+(const Nod&o)const{
        Nod ans;
        ans.mn=min(mn,o.mn); ans.lz=ans.cnt=0;
        if(ans.mn==mn)ans.cnt+=cnt;
        if(ans.mn==o.mn)ans.cnt+=o.cnt;
        return ans;
    }
} nod[N<<2];
void build(int l,int r,int rt) {
    if(l==r) {
        nod[rt].mn=1e9; nod[rt].cnt=1; return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
void pushdown(int rt){
    if(nod[rt].lz){
        nod[rt<<1].lz+=nod[rt].lz; nod[rt<<1].mn+=nod[rt].lz;
        nod[rt<<1|1].lz+=nod[rt].lz; nod[rt<<1|1].mn+=nod[rt].lz;
        nod[rt].lz=0;
    }
}
void update(int l,int r,int rt,int L,int R,int x) {
    if(L<=l&&r<=R){
        nod[rt].lz += x; nod[rt].mn += x; return;
    }
    int mid=(l+r)>>1; pushdown(rt);
    if(L<=mid) update(l,mid,rt<<1,L,R,x);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
Nod query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) return nod[rt];
    int mid=(l+r)>>1; pushdown(rt);
    if(L>mid) return query(mid+1,r,rt<<1|1,L,R);
    if(R<=mid) return query(l,mid,rt<<1,L,R);
    return query(l,mid,rt<<1,L,R)+query(mid+1,r,rt<<1|1,L,R);
}
struct STK {
    pair<int,int> stk[N];
    int top;
    void insert(int pos,int x) {
        while(top && x>stk[top].first) {
            if(top>1) update(1,n,1,stk[top-1].second+1,stk[top].second,x-stk[top].first);
            else update(1,n,1,1,stk[top].second,x-stk[top].first);  
            --top;
        } 
        stk[++top]=make_pair(x,pos);
    } 
} A,B;
void prt(){
    /*
    for(int i=1;i<=n;i++){
        printf("%d ", query(1,n,1,i,i).mn);
    }
    printf("\n");
    */
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int r,c; scanf("%d%d",&r,&c); a[r]=c;
    }
    build(1,n,1);
    prt();
    for(int i=1;i<=n;i++){
        update(1,n,1,i,i,-1e9);
        update(1,n,1,1,i,-1);
        prt();
        A.insert(i,a[i]);
        prt();
        B.insert(i,-a[i]);
        prt();
        if(nod[1].mn==-1)
            ans+=nod[1].cnt;
    }
    cout<<ans<<endl;
}