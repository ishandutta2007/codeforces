#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=50000+5,inf=1e9+7;
int a[N],T,n,x,dp[2][2][N];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        scanf("%d",&x);
        rep(i,n)a[i]-=x;
        dp[1][0][0]=dp[0][1][0]=dp[1][1][0]=-inf;
        dp[0][0][0]=0;
        rep(i,n){
            for(int mk=0;mk<2;++mk)
                dp[mk][0][i]=max(dp[1][mk][i-1],dp[0][mk][i-1]);
            dp[0][1][i]=max(dp[0][0][i-1],dp[1][0][i-1])+1;
            dp[1][1][i]=-inf;
            if(a[i-1]+a[i]>=0)dp[1][1][i]=max(dp[1][1][i],dp[0][1][i-1]+1);
            if(a[i-1]+a[i]>=0&&a[i-2]+a[i-1]+a[i]>=0)
                dp[1][1][i]=max(dp[1][1][i],dp[1][1][i-1]+1);
        }
        int ans=max(max(dp[0][0][n],dp[0][1][n]),max(dp[1][0][n],dp[1][1][n]));
        printf("%d\n",ans);
    }
    return 0;
}
/*


*/