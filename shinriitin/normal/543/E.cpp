#include <stdio.h>
#include <string.h>
#include <algorithm>

#define fi first
#define se second
#define L(x) p[x].l
#define R(x) p[x].r
#define MX(x) p[x].mx
#define UPT(x) max(int(mid>l?MX(L(x)):L(x)),int(r>mid+1?MX(R(x)):R(x)))
#define TAG(x) MX(x)-UPT(x)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define inf 0x7f7f7f7f
using namespace std;

#define g() getchar()
template<class Q>void Scan(Q&x){
    char c;while(c=g(),c<48||c>57);
    for(x=0;c>47&&c<58;c=g())x=10*x+c-48;
}

const int MAXN=2e5+5;
typedef unsigned long long ull;

typedef struct node*star;
struct node{
    ull mx:18,l:23,r:23;
}p[MAXN*40];

int tail;

int update(int x,int l,int r,int ll,int rr){
    if(l==r)return x+1;
    int y=++tail; 
    p[y]=p[x];
    if(ll<=l&&r<=rr)return ++MX(y),y;
    int mid=(l+r)>>1;
    int tag=TAG(x);
    if(ll<=mid)L(y)=update(L(x),l,mid,ll,rr);
    if(rr>mid) R(y)=update(R(x),mid+1,r,ll,rr);
    MX(y)=UPT(y)+tag;
    return y;
}

int query(int x,int l,int r,int ll,int rr){
    if(l==ll&&r==rr)return r>l?MX(x):x;
    int mid=(l+r)>>1;
    int tag=TAG(x);
    if(rr<=mid)return query(L(x),l,mid,ll,rr)+tag;
    if(ll>mid) return query(R(x),mid+1,r,ll,rr)+tag;
    int t1=query(L(x),l,mid,ll,mid);
    int t2=query(R(x),mid+1,r,mid+1,rr);
    return max(t1,t2)+tag;
}

int n,m,Q,rt[MAXN];

pair<int,int>v[MAXN];

inline void Init(){
    Scan(n),Scan(m);
    rep(i,1,n){
        Scan(v[i].fi);
        v[i].fi*=-1;
        v[i].se=i;
    }
    sort(v+1,v+1+n);
    rep(i,1,n){
        int l=max(1,v[i].se-m+1),r=min(n-m+1,v[i].se);
        rt[i]=update(rt[i-1],1,n-m+1,l,r);
    }
}

int ans;

inline void Solve(){
    Scan(Q);
    rep(i,1,Q){
        int l,r,k;
        Scan(l),Scan(r),Scan(k);
        k^=ans;
        k=upper_bound(v+1,v+1+n,make_pair(-k,inf))-v-1;
        ans=m-query(rt[k],1,n-m+1,l,r);
        printf("%d\n",ans);
    }
}

int main(){
    Init(); Solve(); return 0;
}