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
int a[N],b[N],n,m;
bool check(int x){
    rep(i,x)b[i]=a[i];
    sort(b+1,b+x+1);
    ll ss=0;
    for(int i=x;i>=1;i-=2)ss+=b[i];
    return ss<=m;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,n)scanf("%d",a+i);
    int ans=0;
    for(;ans<=n;++ans)if(!check(ans))break;
    --ans;
    printf("%d\n",ans);
    return 0;
}