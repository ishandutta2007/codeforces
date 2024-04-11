#include <iostream>
using namespace std;
typedef long long LL;
const int N=100000 + 10;
int n,m;
int bit[35][N],a[N],l[N],r[N],q[N];
void upd(int id,int pos,int x){
    while(pos<N){
        bit[id][pos] += x; pos += pos&-pos;
    }
}
int que(int id,int pos){
    int ans=0;
    while(pos>0){
        ans+=bit[id][pos]; pos -= pos&-pos;
    }
    return ans;
}
int sum[N<<2];
void build(int l,int r,int rt) {
    if(l==r) {
        sum[rt]=a[l]; return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    sum[rt] = sum[rt<<1] & sum[rt<<1|1];
}
int query(int l,int r,int rt,int L,int R){
    //printf("l=%d,r=%d,rt=%d, %d, %d\n", l,r,rt,L,R);
    if(L<=l&&r<=R) return sum[rt];
    int mid=(l+r)>>1;
    if(R<=mid) return query(l,mid,rt<<1,L,R);
    if(L> mid) return query(mid+1,r,rt<<1|1,L,R);
    return query(l,mid,rt<<1,L,R) & query(mid+1,r,rt<<1|1,L,R); 
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&l[i],&r[i],&q[i]);
        for(int j=0;j<31;j++) {
            if(q[i]>>j&1) {
                upd(j,l[i],1); upd(j,r[i]+1,-1);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=0;j<31;j++) if(que(j,i)) a[i] |= 1<<j;
    }

    build(1,n,1);
    //printf("ok\n");
    bool ok=1;
    for(int i=1;i<=m;i++)
        if(query(1,n,1,l[i],r[i]) != q[i]) ok=0;
    if(!ok) return !printf("NO\n");
    printf("YES\n");
    for(int i=1;i<=n;i++) printf("%d ", a[i]);
}