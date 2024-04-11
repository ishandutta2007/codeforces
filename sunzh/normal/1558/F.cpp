#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
    return f==-1?~x+1:x;
}
int T;
int n;
int a[200010];
int pos[200010];
bool vis[200010];
int mx[800010],sum[800010],tag[800010];
void pushup(int p){
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
void pushdown(int p){
    if(tag[p]){
        mx[p<<1]+=tag[p],mx[p<<1|1]+=tag[p];
        tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];tag[p]=0;
    }
}
void build(int p,int l,int r){
    mx[p]=-(1<<30),sum[p]=tag[p]=0;
    if(l==r) return ;
    int mid=l+r>>1;
    build(p<<1,l,mid);build(p<<1|1,mid+1,r);
}
void change(int p,int l,int r,int pos,int k){
    if(l==r){
        sum[p]=1;mx[p]=k;return ;
    }
    pushdown(p);
    int mid=l+r>>1;
    if(pos<=mid) change(p<<1,l,mid,pos,k);
    else change(p<<1|1,mid+1,r,pos,k);
    pushup(p);
}
void update(int p,int l,int r,int L,int R,int k){
    if(L>R) return ;
    if(l>=L&&r<=R){
        tag[p]+=k;mx[p]+=k;return ;
    }
    int mid=l+r>>1;pushdown(p);
    if(L<=mid) update(p<<1,l,mid,L,R,k);
    if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
    pushup(p);
}
int query(int p,int l,int r,int L,int R){
    if(L>R) return 0;
    if(l>=L&&r<=R) return sum[p];
    int res=0,mid=l+r>>1;
    if(L<=mid) res+=query(p<<1,l,mid,L,R);
    if(R>mid) res+=query(p<<1|1,mid+1,r,L,R);
    return res;
}
int main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i,vis[i]=0;
        build(1,1,n);
        int R=n;
        int ans=0;
        for(int i=n;i>=1;--i){
            // printf("i:%d,pos:%d\n",i,pos[i]);
            update(1,1,n,1,pos[i]-1,-2);
            int p=query(1,1,n,pos[i]+1,n)+1;
            change(1,1,n,pos[i],n-p+1-pos[i]+(pos[i]%2==0)-p);
            vis[pos[i]]=1;
            while(vis[R]){
                change(1,1,n,R,-(1<<30));
                --R;
            }
            ans=max(ans,mx[1]+n-i+1);
        }
        printf("%d\n",ans);
    }
}