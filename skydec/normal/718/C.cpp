#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
const int P=1000000007;
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
    return c;
}
inline void add(int &a,int b){a+=b;if(a>=P)a-=P;}
inline void dec(int &a,int b){a-=b;if(a<0)a+=P;}
struct mat{
    int a[2][2];
    void init(){
        a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
    }
    void unit(){
        a[0][0]=a[1][1]=1;
        a[1][0]=a[0][1]=0;
    }
};
mat S;
inline mat operator +(const mat &a,const mat &b){
    mat c;c.init();
    rep(i,0,1)rep(j,0,1)c.a[i][j]=(a.a[i][j]+b.a[i][j])%P;
    return c;
}
inline mat operator *(const mat &a,const mat &b){
    mat c;c.init();
    rep(i,0,1)rep(j,0,1)c.a[i][j]=(a.a[i][0]*1ll*b.a[0][j]+a.a[i][1]*1ll*b.a[1][j])%P;
    return c;
}
inline mat Pow(mat a,int b){
    mat c;c.unit();
    for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
    return c;
}
mat sum[N<<2],tag[N<<2];
int n,Q;
inline void Tag(int me,mat v){
    tag[me]=tag[me]*v;
    sum[me]=sum[me]*v;
}
inline void down(int me){
    Tag(me<<1,tag[me]);
    Tag(me<<1|1,tag[me]);
    tag[me].unit();
}
inline void addmat(int me,int l,int r,int x,int y,mat v){
    if(l^r)down(me);
    if(x<=l&&r<=y){
        Tag(me,v);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)addmat(me<<1,l,mid,x,y,v);
    if(y>mid)addmat(me<<1|1,mid+1,r,x,y,v);
    sum[me]=sum[me<<1]+sum[me<<1|1];
}
inline mat getsum(int me,int l,int r,int x,int y){
    if(l^r)down(me);
    if(x<=l&&r<=y)return sum[me];
    mat ans;ans.init();
    int mid=(l+r)>>1;
    if(x<=mid)ans=ans+getsum(me<<1,l,mid,x,y);
    if(y>mid)ans=ans+getsum(me<<1|1,mid+1,r,x,y);
    return ans;
}
inline void build(int me,int l,int r){
    tag[me].unit();
    if(l==r){
        int x;scanf("%d",&x);
        sum[me]=Pow(S,x);
        return;
    }
    int mid=(l+r)>>1;
    build(me<<1,l,mid);
    build(me<<1|1,mid+1,r);
    sum[me]=sum[me<<1]+sum[me<<1|1];
}
int main(){
    S.init();
    S.a[1][0]=1;
    S.a[0][1]=S.a[1][1]=1;
    scanf("%d%d",&n,&Q);
    build(1,1,n);
    while(Q--){
        int ty,l,r;scanf("%d%d%d",&ty,&l,&r);
        if(ty==2){
            printf("%d\n",getsum(1,1,n,l,r).a[0][1]);
        }
        else{
            int x;scanf("%d",&x);
            addmat(1,1,n,l,r,Pow(S,x));
        }
    }
    return 0;
}