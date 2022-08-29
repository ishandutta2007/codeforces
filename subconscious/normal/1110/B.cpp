#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fxxkcjb0
#define y0 fxxkcjb1
#define x1 fxxkcjb2
#define y1 fxxkcjb3
#define eb emplace_back
#define fr first
#define sc second
using namespace std;
using namespace std::placeholders;
using ll=long long;
using ld=long double;
using pr=pair<int,int>;
const int N=1e6+5,MOD=1e9+7;
int a[N],b[N],n,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    rep(i,n)scanf("%d",a+i);
    rep(i,n-1)b[i]=a[i+1]-a[i]-1;
    sort(b+1,b+n);
    int ans=n;
    rep(i,n-k)ans+=b[i];
    printf("%d\n",ans);
    return 0;
}