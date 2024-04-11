#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5,mod=1e9+7;
int a[N],b[N],n,T;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        rep(i,n)scanf("%d",b+i);
        sort(a+1,a+n+1);sort(b+1,b+n+1);
        rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
        rep(i,n)printf("%d%c",b[i]," \n"[i==n]);
    }
}