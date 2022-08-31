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
struct que{
    int l,r,key;
}e[N];
int p[N],rp[N],a[N],n,m,q;
int la[N],f[20][N];
char ans[N];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    rep(i,n)scanf("%d",p+i);
    rep(i,n)rp[p[i]]=i;
    rep(i,m)scanf("%d",a+i);
    rep(i,q)scanf("%d%d",&e[i].l,&e[i].r),e[i].key=i;
    sort(e+1,e+q+1,[](que x,que y){return x.l>y.l;});
    int ck=1,cur=m+1;
    rep(i,n)la[i]=m+1;
    for(int i=0;i<20;++i)f[i][m+1]=m+1;
    for(int i=m;i;--i){
        la[a[i]]=i;
        f[0][i]=la[p[rp[a[i]]%n+1]];
        rep(j,19)f[j][i]=f[j-1][f[j-1][i]];
        int jp=i,tmp=n-1;
        for(int j=0;j<20;++j)
            if(tmp&(1<<j))
                jp=f[j][jp];
        cur=min(cur,jp);
        while(ck<=q&&e[ck].l==i){
            ans[e[ck].key]=cur<=e[ck].r?'1':'0';
            ++ck;
        }
    }
    printf("%s\n",ans+1);
    return 0;
}