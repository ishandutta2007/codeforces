#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=600000+10;
int n,m,a[N],las[N],sum[N<<2];
void update(int l,int r,int rt,int pos,int x){
    if(l==r) {
        sum[rt]+=x; return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos,x);
    else update(mid+1,r,rt<<1|1,pos,x);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)return sum[rt];
    int mid=(l+r)>>1,ans=0;
    if(L<=mid)ans+=query(l,mid,rt<<1,L,R);
    if(R >mid)ans+=query(mid+1,r,rt<<1|1,L,R);
    return ans;
}
int mx[N],mn[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)a[i]=n+1-i;
    for(int i=1;i<=n;i++) mx[i]=i,mn[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d",&a[n+i]); mn[a[n+i]]=1;
    }
    n=n+m;
    for(int i=1;i<=n;i++){
        //printf("%d ", a[i]);
        if(las[a[i]]){
            update(1,n,1,las[a[i]],-1);
            if(las[a[i]]+1<=i-1)
            mx[a[i]] = max(mx[a[i]],query(1,n,1,las[a[i]]+1,i-1)+1);
        }
        las[a[i]]=i;
        update(1,n,1,i,1);
    }
    for(int i=1;i<=n;i++){
        if(las[i]+1<=n)
        mx[i]=max(mx[i],query(1,n,1,las[i]+1,n)+1);
    }
    printf("\n");
    for(int i=1;i<=n-m;i++){
        printf("%d %d\n", mn[i],mx[i]);
    }
}