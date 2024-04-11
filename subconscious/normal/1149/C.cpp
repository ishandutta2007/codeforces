#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define eb emplace_back
#define mp make_pair
#define st first
#define nd second
#define x0 fxxk
#define y0 fxck
#define x1 fuxk
#define y1 fucx
using namespace std;
using ll=long long;
using ld=long double;
using pr=pair<int,int>;
constexpr int N=2e5+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
struct node{
    int mx,ml,mr,dl,dr,xl,xr;
    node operator+(node p){
        return {
            max(max(mx,p.mx),max(mr+p.dl,dr+p.ml)),
            max(ml,max(xl+xr+p.dl,xl-xr+p.ml)),
            max(p.mr,max(dr+p.xl+p.xr,mr-p.xl+p.xr)),
            max(dl,p.dl-xl+xr),
            max(p.dr,dr-p.xr+p.xl),
            xr<p.xl?xl+p.xl-xr:xl,
            xr>p.xl?xr-p.xl+p.xr:p.xr
        };
    }
}a[N<<2];
int n,q;
char s[N];
void flp(int co,int l,int r,int pos){
    if(l==r){
        s[l]=s[l]=='('?')':'(';
        if(s[l]=='(')a[co]={1,1,1,1,0,0,1};
        else a[co]={1,1,1,0,1,1,0};
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)flp(co<<1,l,mid,pos);
    else flp(co<<1|1,mid+1,r,pos);
    a[co]=a[co<<1]+a[co<<1|1];
}
void init(int co,int l,int r){
    if(l==r){
        if(s[l]=='(')a[co]={1,1,1,1,0,0,1};
        else a[co]={1,1,1,0,1,1,0};
        return;
    }
    int mid=(l+r)>>1;
    init(co<<1,l,mid);
    init(co<<1|1,mid+1,r);
    a[co]=a[co<<1]+a[co<<1|1];
    //printf("%d %d %d\n",co,a[co].mx,a[co].ml);
}
int main(){
    scanf("%d%d",&n,&q);n=2*n-2;
    scanf("%s",s+1);
    init(1,1,n);
    printf("%d\n",a[1].mx);
    rep(i,q){
        int x,y;scanf("%d%d",&x,&y);
        flp(1,1,n,x);
        flp(1,1,n,y);
        printf("%d\n",a[1].mx);
    }
    return 0;
}