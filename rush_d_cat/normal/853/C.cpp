#include <iostream>
#include <algorithm>
using namespace std;
const int N=6000000+10;
#define f(x) (1LL*x*(x-1)/2)
typedef long long LL;
int lson[N],rson[N],sum[N],root[N],pid;
int n,q,p[N];
void build(int &k,int l,int r){
    k=++pid;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(lson[k],l,mid);
    build(rson[k],mid+1,r);
}
void change(int old,int &k,int l,int r,int pos,int x) {
    k=++pid;
    lson[k]=lson[old],rson[k]=rson[old],sum[k]=sum[old]+x;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(pos<=mid) change(lson[k],lson[k],l,mid,pos,x);
    else change(rson[k],rson[k],mid+1,r,pos,x);
}
int query(int new_k,int old_k,int l,int r,int x) { // cnt <= x
    if(x<l) return 0;
    if(l==r) return sum[new_k]-sum[old_k];
    int mid=(l+r)>>1;
    if(mid<x) return sum[lson[new_k]]-sum[lson[old_k]]+query(rson[new_k],rson[old_k],mid+1,r,x);
    else return query(lson[new_k],lson[old_k],l,mid,x);
}
int count(int x1,int x2,int y1,int y2) { // 
    if(x1>x2||y1>y2) return 0;
    int cnt1 = query(root[x2],root[x1-1],1,n,y1-1);
    int cnt2 = query(root[x2],root[x1-1],1,n,y2);
    return cnt2-cnt1;
} 
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
    }
    build(root[0],1,n);
    for(int i=1;i<=n;i++) {
        change(root[i-1],root[i],1,n,p[i],1);
    }
    for(int i=1;i<=q;i++){
        int l,d,r,u;
        scanf("%d%d%d%d",&l,&d,&r,&u);
        int LU = count(1,l-1,u+1,n);
        int LD = count(1,l-1,1,d-1);
        int RU = count(r+1,n,u+1,n);
        int RD = count(r+1,n,1,d-1);

        int L = l-1; int U = n-u; 
        int R = n-r; int D = d-1;
        
        LL A = f(L)+f(R)+f(U)+f(D);
        LL B = f(LU)+f(LD)+f(RU)+f(RD);
        LL ret = 1LL*n*(n-1)/2-(A-B);
        printf("%lld\n", ret);
    }
}