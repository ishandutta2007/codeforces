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
int a[N],b,k;
int main(){
    scanf("%d%d",&b,&k);
    rep(i,k)scanf("%d",a+i);
    reverse(a+1,a+k+1);
    int s=0,p=1;
    rep(i,k){
        s=(s+1ll*a[i]*p)%2;
        p=1ll*p*b%2;
    }
    puts(s==0?"even":"odd");
    return 0;
}