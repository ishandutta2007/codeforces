#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
#define eb emplace_back
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
vector<int>a[N];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    rep(i,m){
        int x,y;
        scanf("%d%d",&x,&y);--x,--y;
        a[x].eb(y);
    }
    rep(i,n)sort(a[i].begin(),a[i].end(),[i](int x,int y){return (x-i+n)%n<(y-i+n)%n;});
    rep(i,n){
        ll ans=0;
        rep(j,n)if(a[j].size()){
            ans=max(ans,(j-i+n)%n+1ll*((ll)a[j].size()-1)*n+(a[j][0]-j+n)%n);
        }
        printf("%lld%c",ans," \n"[i==n-1]);
    }
    return 0;
}