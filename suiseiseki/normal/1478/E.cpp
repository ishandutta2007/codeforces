#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int maxn=2e5+10;

char s[maxn],f[maxn];
int n,q,l[maxn],r[maxn];
int sum[maxn<<2],lazy[maxn<<2],L,R;

inline void update(int x){
    sum[x]=sum[x<<1]+sum[x<<1|1];
}

void build(int l,int r,int x){
    lazy[x]=-1;
    if(l==r){
        sum[x]=f[l-1]-'0';
        return;
    }
    int mid=l+r>>1;
    build(l,mid,x<<1);
    build(mid+1,r,x<<1|1);
    update(x);
}

inline void put_lazy(int l,int r,int x,int k){
    lazy[x]=k;
    sum[x]=(r-l+1)*k;
}

inline void down_lazy(int l,int r,int x){
    int mid=l+r>>1;
    put_lazy(l,mid,x<<1,lazy[x]);
    put_lazy(mid+1,r,x<<1|1,lazy[x]);
    lazy[x]=-1;
}

void modify(int l,int r,int x,int k){
    if(L<=l&&r<=R){
        put_lazy(l,r,x,k);
        return;
    }
    if(~lazy[x]) down_lazy(l,r,x);
    int mid=l+r>>1;
    if(L<=mid) modify(l,mid,x<<1,k);
    if(mid<R) modify(mid+1,r,x<<1|1,k);
    update(x);
}

int query(int l,int r,int x){
    if(L<=l&&r<=R) return sum[x];
    if(~lazy[x]) down_lazy(l,r,x);
    int mid=l+r>>1,ans=0;
    if(L<=mid) ans+=query(l,mid,x<<1);
    if(mid<R) ans+=query(mid+1,r,x<<1|1);
    return ans;
}

bool check(int l,int r,int x){
    if(l==r){
        return sum[x]==s[l-1]-'0';
    }
    if(~lazy[x]) down_lazy(l,r,x);
    int mid=l+r>>1;
    return check(l,mid,x<<1)&&check(mid+1,r,x<<1|1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d %d %s %s",&n,&q,s,f);
        build(1,n,1);
        for(int i=1;i<=q;i++) scanf("%d %d",&l[i],&r[i]);
        bool f=1;
        for(int i=q;i>=1;i--){
            L=l[i],R=r[i];
            int res=query(1,n,1);
            if((R-L)&1&&(R-L+1)>>1==res){
                f=0;break;
            }
            if(res>(R-L+1)>>1) modify(1,n,1,1);
            else modify(1,n,1,0);
            L=1,R=1;
        }
        if(f&&check(1,n,1)) puts("YES");
        else puts("NO");
    }
    return 0;
}