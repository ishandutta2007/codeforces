#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
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
typedef vector<int> vi;
const int N=3e6+5,mod=1e9+7;
const ll inf=1e18;
int n,m,a[N],T;ll dp[2][N];
vector<pr>b[N];
pr l[N];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        rep(i,n)scanf("%d",a+i);
        sort(a+1,a+n+1);
        //rep(i,n)printf("%d\n",a[i]);

        rep(i,n+1)b[i].clear();
        rep(i,m)scanf("%d%d",&l[i].st,&l[i].nd);
        sort(l+1,l+m+1);
        int top=0;
        rep(i,m){
            while(top>0&&l[i].nd<=l[top].nd)--top;
            l[++top]=l[i];
        }
        m=top;
        int ptr=1;
        rep(i,m){
            while(ptr<=n&&a[ptr]<l[i].st)++ptr;
            if(ptr<=n&&l[i].st<=a[ptr]&&a[ptr]<=l[i].nd)continue;
            //printf("%d %d\n",l[i].st,l[i].nd);
            b[ptr].pb(l[i]);
        }
        ll ans=0;
        if(b[1].size()==0)
            dp[0][1]=dp[1][1]=0;
        else
            dp[0][1]=a[1]-b[1][0].nd,dp[1][1]=2ll*(a[1]-b[1][0].nd);
        for(int i=2;i<=n;++i){
            if(b[i].size()==0){
                dp[1][i]=dp[0][i]=min(dp[0][i-1],dp[1][i-1]);
            }else{
                dp[0][i]=dp[1][i]=inf;
                for(int j=0,siz=b[i].size();j<=siz;++j)
                    for(int typ0=0;typ0<=1;++typ0)
                        for(int typ1=0;typ1<=1;++typ1)
                            dp[typ1][i]=min(
                                dp[typ1][i]
                                ,dp[typ0][i-1]
                                +(typ0==0?2ll:1ll)*(j==0?0:(b[i][j-1].st-a[i-1]))
                                +(typ1==0?1ll:2ll)*(j==siz?0:(a[i]-b[i][j].nd))
                            );
            }
            //printf("%lld %lld\n",dp[0][i],dp[1][i]);
        }
        if(b[n+1].size()==0)ans=min(dp[0][n],dp[1][n]);
        else ans=min(dp[0][n]+2ll*(b[n+1].back().st-a[n]),dp[1][n]+(b[n+1].back().st-a[n]));
        printf("%lld\n",ans);
    }

    return 0;
}
/*
1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19
*/