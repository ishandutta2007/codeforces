#include <stdio.h>
#include <string.h>
#include <algorithm>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define lch lc(x),l,mid
#define rch rc(x),mid+1,r
using namespace std;

#define g() getchar()
template<class Q>inline void Scan(Q&x){
    char c; int f=1;
    while(c=g(),c<48||c>57)if(c=='-')f=-1;
    for(x=0;c>47&&c<58;c=g())x=10*x+c-48;
    x*=f;
}

const int MAXN=1e5+5;
typedef long long ll;

int n,m,a[MAXN];

ll sum[MAXN<<2];

int mx[MAXN<<2],pos[MAXN];

inline void update(int x){
    sum[x]=sum[lc(x)]+sum[rc(x)];
    mx[x]=max(mx[lc(x)],mx[rc(x)]);
}

void build(int x,int l,int r){
    if(l==r){
        sum[x]=mx[x]=a[l];
        pos[l]=x;
        return;
    }
    int mid=(l+r)>>1;
    build(lch),build(rch);
    update(x);
}

inline void set_val(int x,int y){
    x=pos[x],sum[x]=mx[x]=y;
    for(x>>=1;x;x>>=1)update(x);
}

void Mod(int x,int l,int r,int ll,int rr,int y){
    if(mx[x]<y)return;
    if(l==r){
        sum[x]=mx[x]=sum[x]%y;
        return;
    }
    int mid=(l+r)>>1;
    if(ll<=mid)Mod(lch,ll,rr,y);
    if(rr>mid) Mod(rch,ll,rr,y);
    update(x);
}

ll query(int x,int l,int r,int ll,int rr){
    if(l==ll&&r==rr)return sum[x];
    int mid=(l+r)>>1;
    if(rr<=mid)return query(lch,ll,rr);
    if(ll>mid) return query(rch,ll,rr);
    return query(lch,ll,mid)+query(rch,mid+1,rr);
}

inline void set_IO(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
}

int main(){
    //set_IO();
    Scan(n),Scan(m);
    for(int i=1;i<=n;++i){
        Scan(a[i]);
    }
    build(1,1,n);
    for(int i=1,tp;i<=m;++i){
        Scan(tp);
        if(tp==1){
            int l,r;
            Scan(l),Scan(r);
            printf("%I64d\n",query(1,1,n,l,r));
        }
        else if(tp==2){
            int l,r,x;
            Scan(l),Scan(r),Scan(x);
            Mod(1,1,n,l,r,x);
        }
        else{
            int x,y;
            Scan(x),Scan(y);
            set_val(x,y);
        }
    }
    return 0;
}