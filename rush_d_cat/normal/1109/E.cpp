#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N=100000+10;
typedef long long LL;

vector< pair<int,int> > v;
int n,q,mod,a[N];
int phi(int x) {
    LL ans=x;
    for(int i=0;i<v.size();i++){
        if(x%v[i].first == 0) {
            ans = ans * 1LL* (v[i].first - 1) / v[i].first;
        }
    }
    return ans;
}
struct Nod{
    LL sum,lzm;
    Nod operator + (const Nod&o) const{
        Nod ans;
        ans.sum=(sum+o.sum)%mod;
        ans.lzm=1;
        return ans;
    }
}nod[N<<2];
void pushdown(int rt){
    if(nod[rt].lzm != 1) {
        nod[rt<<1].sum = nod[rt<<1].sum * nod[rt].lzm % mod;
        nod[rt<<1].lzm = nod[rt<<1].lzm * nod[rt].lzm % mod;
        nod[rt<<1|1].sum = nod[rt<<1|1].sum * nod[rt].lzm % mod;
        nod[rt<<1|1].lzm = nod[rt<<1|1].lzm * nod[rt].lzm % mod;
        nod[rt].lzm = 1;
    }
}
void build(int l,int r,int rt){
    nod[rt].lzm=1;
    if(l==r) {
        nod[rt].sum=1; return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}

LL mpow(LL a,LL x) {
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0) return t*t%mod;
    return t*t%mod*a%mod;
}

int bitc[12][N];LL bitv[N];
void add1(int id,int pos,int x){
    //if(x)
    //printf("id=%d,pos=%d,x=%d\n", id,pos,x);
    while(pos<N){
        bitc[id][pos] += x; pos += pos&-pos;
    }
}
void add2(int pos,int x){
    while(pos<N){
        bitv[pos] = bitv[pos] * x % mod; pos += pos & -pos;
    }
}
void modify(int l,int r,int rt,int L,int R,int x) {
    if(L<=l&&r<=R){
        nod[rt].sum = nod[rt].sum * x % mod;
        nod[rt].lzm = nod[rt].lzm * x % mod; 
        //printf("# %d %d %d\n", l,r,nod[rt].sum);
        return;
    }
    pushdown(rt); int mid=(l+r)>>1;
    if(L<=mid) modify(l,mid,rt<<1,L,R,x);
    if(R >mid) modify(mid+1,r,rt<<1|1,L,R,x);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
void change(int l,int r,int rt,int pos,int x){
    if(l==r) {
        nod[rt].sum=x, nod[rt].lzm=1; return;
    }
    int mid=(l+r)>>1; pushdown(rt);
    if(pos<=mid) change(l,mid,rt<<1,pos,x);
    else change(mid+1,r,rt<<1|1,pos,x);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
int get(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) {
        return nod[rt].sum;
    }
    pushdown(rt); int mid=(l+r)>>1;
    int ans=0;
    if(L<=mid) ans = ans + get(l,mid,rt<<1,L,R);
    if(R >mid) ans = ans + get(mid+1,r,rt<<1|1,L,R);
    return ans % mod;
}
void update(int l,int r,int x) {
    modify(1,n,1,l,r,x);
    
    for(int i=0;i<v.size();i++) {
        int cnt=0;
        while(x%v[i].first == 0) cnt++, x/=v[i].first;
        add1(i,l,cnt), add1(i,r+1,-cnt);
    }
    add2(l,x); add2(r+1,mpow(x,phi(mod) - 1));
}

int query(int pos) {
    int ppos = pos;
    int c[12]={0}; LL M=1;
    while(pos>0){
        for(int i=0;i<v.size();i++) c[i] += bitc[i][pos];
        M=M*bitv[pos]%mod; pos -= pos&-pos;
    }
    
    for(int i=0;i<v.size();i++){
        M=M*mpow(v[i].first, c[i])%mod;
    }
    //printf("ppos = %d, M = %d\n", ppos, M);
    change(1,n,1, ppos,M);
    return M;
}
void divide(int pos,int x) {
    for(int i=0;i<v.size();i++){
        int cnt=0;
        while(x%v[i].first == 0) x/=v[i].first, cnt ++;
        add1(i,pos,-cnt); add1(i,pos+1,cnt);
    }
    add2(pos,mpow(x,phi(mod)-1)); add2(pos+1,x);
    int val = query(pos);
}
int main(){
    scanf("%d%d",&n,&mod);
    
    int tmp=mod;
    for(int i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            int cnt=0;
            while(tmp%i==0){
                tmp/=i; ++cnt;
            }
            v.push_back(make_pair(i,cnt));
        }
    }
    if(tmp>1) v.push_back(make_pair(tmp,1));

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<N;i++) bitv[i]=1;
    build(1,n,1);
    for(int i=1;i<=n;i++) update(i,i,a[i]);

    scanf("%d", &q);
    while(q--){
        int op,l,r,p,x;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&l,&r,&x);
            update(l,r,x);
        }
        if(op==2){
            //printf("-------------\n");
            scanf("%d%d",&p,&x);
            divide(p,x);
        }
        if(op==3){
            scanf("%d%d",&l,&r);
            printf("%d\n", get(1,n,1,l,r));
        }

    }
}