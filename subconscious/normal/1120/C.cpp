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
constexpr int N=5005,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
char s[N];
int d[N],lcs[N][N],n,a,b;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s+1);
    for(int i=n;i;--i)
        for(int j=n;j;--j)
            lcs[i][j]=(s[i]==s[j]?lcs[i+1][j+1]+1:0);
    rep(i,n)d[i]=mod;
    rep(i,n){
        int mx=0;
        rep(j,i-1)
            mx=max(mx,min(lcs[i][j],i-j));
        d[i]=min(d[i],d[i-1]+a);
        d[i+mx-1]=min(d[i+mx-1],d[i-1]+b);
    }
    printf("%d\n",d[n]);
    return 0;

}