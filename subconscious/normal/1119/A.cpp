#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckcjb
#define y0 fxxkcjb
#define x1 fckxcjb
#define y1 fasdlfj
#define ep emplace_back
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e6+5,mod=1e9+7;
constexpr ld inf=1e50,eps=1e-10;
int a[N],n;
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    int ans=0;
    if(a[1]!=a[n])ans=n-1;
    rep(i,n)if(a[i]!=a[1])ans=max(ans,n-i);
    rep(i,n)if(a[i]!=a[n])ans=max(ans,i-1);
    printf("%d\n",ans);
    return 0;
}