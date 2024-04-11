#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N=1000000+10;

int n,k,a[N];
int mx[N<<2],lz[N<<2],pre[N];
int stk[N],top;
void pushdown(int rt){
    if(lz[rt]){
        mx[rt<<1]=mx[rt<<1] + lz[rt]; 
        lz[rt<<1]=lz[rt<<1] + lz[rt];
        mx[rt<<1|1] = mx[rt<<1|1] + lz[rt];  
        lz[rt<<1|1] = lz[rt<<1|1] + lz[rt];
        lz[rt]=0;
    }
}
void update(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R){
        lz[rt]++; mx[rt]++; return;
    }
    pushdown(rt); int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,rt<<1,L,R);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
int query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) {
        //printf("[%d, %d] %d\n", l,r,mx[rt]);
        return mx[rt];
    }
    pushdown(rt); int mid=(l+r)>>1; 
    int ans=0;
    if(L<=mid)ans=max(ans,query(l,mid,rt<<1,L,R));
    if(R >mid)ans=max(ans,query(mid+1,r,rt<<1|1,L,R));
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++){
        while(top && a[stk[top]] < a[i]) -- top;
        pre[i]=stk[top]; stk[++top]=i;
    }

    for(int i=1;i<=n;i++) {
        int L=max(pre[i]+1, i-k+1);
        int R=i;
        //printf("upd %d %d\n", L,R);
        update(1,n,1,L,R);
        if(i>=k){
            int lef=max(i-k+1,1);
            //printf("Q %d %d\n", lef,R);
            printf("%d ", query(1,n,1,lef,R));
        }
    }
}