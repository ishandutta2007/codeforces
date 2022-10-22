#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=800000;
int val[maxn],a[maxn],lazy[maxn];
void build(int x,int l,int r){
    if (l==r) val[x]=a[l];
    else{
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
    }   
}
void change(int x,int l,int r,int p,int v){
    if (l==r){
        lazy[x]=0; val[x]=v;
    }else{
        int mid=l+r>>1;
        if (lazy[x]){
            lazy[x<<1]=max(lazy[x<<1],lazy[x]);
            lazy[x<<1|1]=max(lazy[x<<1|1],lazy[x]);
            lazy[x]=0;
        }
        if (p<=mid) change(x<<1,l,mid,p,v);
        if (p>mid) change(x<<1|1,mid+1,r,p,v);
    }
}
void dfs(int x,int l,int r){
    if (l==r) a[l]=max(lazy[x],val[x]);
    else{
        int mid=l+r>>1;
        if (lazy[x]){
            lazy[x<<1]=max(lazy[x<<1],lazy[x]);
            lazy[x<<1|1]=max(lazy[x<<1|1],lazy[x]);
            lazy[x]=0;
        }
        dfs(x<<1,l,mid);
        dfs(x<<1|1,mid+1,r);
    }   
}
int n,q;
int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&q);
    while (q--){
        int type;
        scanf("%d",&type);
        if (type==1){
            int p,v;
            scanf("%d%d",&p,&v);
            change(1,1,n,p,v);
        }
        if (type==2){
            int v;
            scanf("%d",&v);
            if (v>lazy[1]) lazy[1]=v;
        }
    }
    dfs(1,1,n);
    for (int i=1; i<=n; i++) printf("%d ",a[i]);
    return 0;
}