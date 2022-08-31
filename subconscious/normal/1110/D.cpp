#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rez(i,n) for(int i=0;i<n;++i)
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
int a[N],d[3][3][N],n,m;
int main(){
    scanf("%d%d",&n,&m);
    rep(i,n){
        int x;scanf("%d",&x);++a[x];
    }
    rez(i,3)rez(j,3)rez(k,m+3){
        //printf("%d %d %d\n",i,j,k);
        d[i][j][k]=-MOD;
    }
    d[0][0][0]=0;
    rep(k,m+2)rez(i,3)rez(j,3){
        int mx=2;
        if(k<3)mx=0;else mx=min(mx,min(a[k],min(a[k-1]-j,a[k-2]-i-j)));
        rez(p,mx+1)d[j][p][k]=max(d[j][p][k],d[i][j][k-1]+p+((k-2>0)?(a[k-2]-i-j-p)/3:0));
    }
    int ans=0;
    rez(i,3)rez(j,3)ans=max(ans,d[i][j][m+2]);
    printf("%d\n",ans);
    return 0;
}