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
bool check(){
    int ans=a[1]*a[n];
    rep(i,n/4){
        int l=i*2-1,r=n-l+1;
        if(a[l]*a[r]!=ans)return 0;
        if(a[l]!=a[l+1]||a[r]!=a[r-1])return 0;
    }
    return 1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);n<<=2;
        rep(i,n)scanf("%d",a+i);
        sort(a+1,a+n+1);
        puts(check()?"YES":"NO");
    }
    return 0;
}