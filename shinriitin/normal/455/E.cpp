#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define g() getchar()
template<class Q>inline void Scan(Q&x){
    char c; int f=1;
    while(c=g(),c<48||c>57)if(c=='-')f=-1;
    for(x=0;c>47&&c<58;c=g())x=10*x+c-48;
    x*=f;
}

#define lch x->l,l,mid
#define rch x->r,mid+1,r
#define rep(i,a,b) for(int i=a;i<b;++i)

const int MAXN=1e5+5;

typedef long long ll;

struct poi{
    ll x,y;
    poi(ll x=0,ll y=0):x(x),y(y){}
    inline bool operator<(const poi&o)const{
        return x!=o.x?x<o.x:y<o.y;
    }
    friend poi operator-(const poi&a,const poi&b){
        return poi(a.x-b.x,a.y-b.y);
    }
    friend ll cross(const poi&a,const poi&b){
        return a.x*b.y-a.y*b.x;
    }
}p[MAXN];

typedef vector<poi>convex;

inline void merge(convex&st,const convex&a,const convex&b){
    int s1=a.size(),s2=b.size();
    int i1=0,i2=0,top=-1;
    while(i1<s1||i2<s2){
        poi p=(i2==s2||(i1<s1&&a[i1]<b[i2]))?a[i1++]:b[i2++];
        while(top>0&&cross(p-st[top-1],st[top]-st[top-1])>=0)
            st.pop_back(),--top;
        st.push_back(p),++top;
    }
}

typedef struct node*star;
struct node{
    convex hull;
    star l,r;
    inline void update(){
        merge(hull,l->hull,r->hull);
    }
}pool[MAXN<<2];
star tail=pool;
void build(star&x,int l,int r){
    x=tail++;
    if(l==r){
        x->hull.push_back(p[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(lch),build(rch);
    x->update();
}

inline ll calc(convex&p,ll a){
    int l=0,r=p.size();--r;
    while(r-l>2){
        int m1=(l+l+r)/3,m2=(l+r+r)/3;
        ll a1=p[m1].x*a+p[m1].y;
        ll a2=p[m2].x*a+p[m2].y;
        if(a1>a2)l=m1;
        else r=m2;
    }
    ll res=1ll<<60;
    rep(i,l,r+1){
        ll tmp=p[i].x*a+p[i].y;
        if(res>tmp)res=tmp;
    }
    return res;
}

ll a,ans;

ll query(star x,int l,int r,int ll,int rr){
    if(l==ll&&r==rr)return calc(x->hull,a);
    int mid=(l+r)>>1;
    if(rr<=mid)return query(lch,ll,rr);
    if(ll>mid) return query(rch,ll,rr);
    return min(query(lch,ll,mid),query(rch,mid+1,rr));
}

int n,m;

ll w[MAXN],s[MAXN];

star rt;

inline void Init(){
    Scan(n);
    rep(i,1,n+1){
        Scan(w[i]);
        s[i]=s[i-1]+w[i];
        p[i]=poi(w[i],w[i]*i-s[i]);
    }
    build(rt,1,n);
}

inline void Solve(){
    Scan(m);
    rep(i,1,m+1){
        int x,y;
        Scan(x),Scan(y);
        a=x-y;
        ans=query(rt,1,n,y-x+1,y)+s[y];
        printf("%I64d\n",ans);
    }
}

int main(){
    Init(); Solve(); return 0;
}