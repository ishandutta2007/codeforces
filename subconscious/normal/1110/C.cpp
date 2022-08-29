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
int a[30],q,n;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
    scanf("%d",&q);
    rep(i,25){
        int n=(1<<i)-1;
        rep(j,n-1)if(n%j==0)a[i]=j;
    }
    rep(i,q){
        scanf("%d",&n);int f=0,g=0;
        rep(j,26)if(n==(1<<j)-1){printf("%d\n",a[j]);f=1;break;}
        else if((1<<j)>n){g=j;break;}
        if(f==0)printf("%d\n",(1<<g)-1);
    }
    return 0;
}