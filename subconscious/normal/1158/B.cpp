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
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    rep(i,n)printf("%d",i%((n-k)/2+1)==0);puts("");
    return 0;
}