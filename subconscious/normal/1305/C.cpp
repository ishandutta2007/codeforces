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
int a[N],is[N],n,m;
int main(){
    scanf("%d%d",&n,&m);
    rep(i,n)scanf("%d",a+i);
    sort(a+1,a+n+1);
    rep(i,n)a[i]%=m;
    bool fg=0;
    rep(i,n){
        ++is[a[i]];
        if(is[a[i]]>1)fg=1;
    }
    if(fg){puts("0");return 0;}
    int ans=1;
    rep(i,n)rep(j,i-1)ans=1ll*ans*(m+a[i]-a[j])%m;
    printf("%d\n",ans);
}