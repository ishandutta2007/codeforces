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
constexpr int N=2e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
struct poi{
    ll x,y;int key;
    poi operator-(poi p){return {x-p.x,y-p.y};}
    ll operator*(poi p){return x*p.y-y*p.x;}
    void scan(int _key){
        scanf("%lld%lld",&x,&y);
        key=_key;
    }
}a[N];
char s[N];
int ans[N],n;bool in[N];
bool cmp_xy(poi p,poi q){
    if(p.x!=q.x)return p.x<q.x;
    return p.y<q.y;
}
bool check(ll ss,char typ){
    return (typ=='L')^(ss>0);
}
int main(){
    scanf("%d",&n);
    rep(i,n)a[i].scan(i);
    scanf("%s",s+2);//st 2
    sort(a+1,a+n+1,cmp_xy);
    rep(i,n)in[i]=1;
    in[1]=0;ans[1]=a[1].key;
    int la=1;
    for(int tim=2;tim<=n;++tim){
        int cur=-1;
        rep(i,n)if((cur==-1&&in[i]==1)||(in[i]==1&&check((a[cur]-a[la])*(a[i]-a[la]),s[tim])))
            cur=i;
        ans[tim]=a[cur].key;in[cur]=0;la=cur;
    }
    rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}