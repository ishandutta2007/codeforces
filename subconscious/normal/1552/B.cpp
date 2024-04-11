#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,inf=1e9+7;
int n,T,a[N][6];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)rep(j,5)scanf("%d",a[i]+j);
        int mx=n;
        rep(i,n-1){
            int cnt=0;
            rep(j,5)cnt+=(a[i][j]<a[mx][j]);
            if(cnt>=3)mx=i;
        }
        bool flag=0;
        rep(i,n){
            if(i==mx)continue;
            int cnt=0;
            rep(j,5)cnt+=(a[i][j]<a[mx][j]);
            if(cnt>=3){flag=1;break;}
        }
        if(flag)puts("-1");else printf("%d\n",mx);
    }

    return 0;
}