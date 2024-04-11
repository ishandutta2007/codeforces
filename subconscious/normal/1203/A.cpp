#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
const double eps=1e-9;
const int N=1e6+5;
int a[N],n,T;
bool sol(){
    int pos=1;
    rep(i,n)if(a[i]==1)pos=i;
    rep(i,n-1){
        if(a[pos%n+1]!=a[pos]+1)return 0;
        pos=pos%n+1;
    }
    return 1;
}
bool check(){
    if(sol())return 1;
    reverse(a+1,a+n+1);
    return sol();
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        puts(check()?"YES":"NO");
    }
    return 0;
}