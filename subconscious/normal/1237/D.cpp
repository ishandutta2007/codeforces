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
const ld eps=1e-9;
const int N=(int)2e6+5;
int a[N],n,pm[22][N];
int ans[N];
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i),a[i+2*n]=a[i+3*n]=a[i+n]=a[i];
    rep(i,n*4)pm[0][i]=a[i];
    rep(i,21)rep(j,n*4-(1<<(i-1)))
        pm[i][j]=min(pm[i-1][j],pm[i-1][j+(1<<(i-1))]);
    ans[n]=n;
    int mx=(a[n]-1)/2;
    for(int i=n+1;i<=4*n;++i){
        mx=max(mx,(a[i]-1)/2);
        //printf("%d %d %d\n",i,mx,a[i]);
        if(mx>=a[i]){
            break;
        }
        ans[n]=i;
    }
    if(ans[n]>=4*n){
        rep(i,n)printf("%d%c",-1," \n"[i==n]);return 0;
    }else{
        for(int i=n-1;i;--i){
            ans[i]=ans[i+1];
            int jp=i;
            for(int j=21;~j;--j)if(pm[j][jp]>(a[i]-1)/2)
                jp+=(1<<j);
            --jp;
            ans[i]=min(ans[i],jp);
        }
    }
    rep(i,n)printf("%d%c",ans[i]-i+1," \n"[i==n]);
    return 0;
}