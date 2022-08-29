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
constexpr int N=505,mod=1e9+7;
constexpr ld inf=1e50,eps=1e-10;
int a[N][N],b[N][N],n,m;
bool check(){
    rep(i,n)rep(j,m)if(a[i][j]!=b[i][j])return 0;return 1;}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,n)rep(j,m)scanf("%d",a[i]+j);
    rep(i,n)rep(j,m)scanf("%d",b[i]+j);
    rep(i,n-1)rep(j,m-1)if(a[i][j]!=b[i][j]){
        a[i][j]^=1;
        a[i+1][j]^=1;
        a[i][j+1]^=1;
        a[i+1][j+1]^=1;
    }
    puts(check()?"Yes":"No");
    return 0;
}