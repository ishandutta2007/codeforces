#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
struct poi{
    ll x,y;
    poi operator-(poi p){return {x-p.x,y-p.y};}
    ll operator*(poi p){return x*p.y-y*p.x;}
    void scan(){scanf("%lld%lld",&x,&y);y-=x*x;}
}a[N];
int n;
int main(){
    scanf("%d",&n);
    rep(i,n)a[i].scan();
    sort(a+1,a+n+1,[](poi x,poi y){return x.x==y.x?x.y<y.y:x.x<y.x;});
    int top=0;
    rep(i,n){
        while(top>1&&(a[top]-a[top-1])*(a[i]-a[top-1])>=0)--top;
        a[++top]=a[i];
    }
    n=top;
    int ans=0;
    rep(i,n-1)if(a[i].x!=a[i+1].x)++ans;
    printf("%d\n",ans);
    return 0;
}