#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
int from[1111][1111];
void print(int len,int ost){
    if(len==1)
        return;
    print(len-2,from[len][ost]);
    if(ost==len)
        printf("%d %d\n",len-1,from[len][ost]);
    else if(ost==len-1)
        printf("%d %d\n",len,from[len][ost]);
    else
        printf("%d %d\n",len,len-1);
}
void solve(){
    int n,x[1111];
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d",&x[i]);
    }
    li dp[1111][1111]; //Length+unused;
    const li INF=1LL<<60;
    for(int i=0;i<1111;++i){
        for(int j=0;j<1111;++j)
            dp[i][j]=INF;
    }
    dp[1][1]=0;
    for(int len=3;len<=n;len+=2){
        for(int ost=1;ost<len-1;++ost){
            if(dp[len][ost]>dp[len-2][ost]+max(x[len],x[len-1])){
                dp[len][ost]=min(dp[len][ost],dp[len-2][ost]+max(x[len],x[len-1]));
                from[len][ost]=ost;
            }
            if(dp[len][len]>dp[len-2][ost]+max(x[len-1],x[ost])){
                dp[len][len]=min(dp[len][len],dp[len-2][ost]+max(x[len-1],x[ost]));
                from[len][len]=ost;
            }
            if(dp[len][len-1]>dp[len-2][ost]+max(x[len],x[ost])){
                dp[len][len-1]=min(dp[len][len-1],dp[len-2][ost]+max(x[len],x[ost]));
                from[len][len-1]=ost;
            }
        }
    }
    li ans=INF;
    li t=0;
    if(n%2){
        for(int ost=1;ost<=n;++ost){
            if(ans>dp[n][ost]+x[ost]){
                ans=min(ans,dp[n][ost]+x[ost]);
                t=ost;
            }
        }
        cout<<ans<<endl;
        print(n,t);
        cout<<t;
    }
    else{
        for(int ost=1;ost<=n;++ost){
            if(ans>dp[n-1][ost]+max(x[ost],x[n])){
            ans=min(ans,dp[n-1][ost]+max(x[ost],x[n]));
            t=ost;
            }
        }
        cout<<ans<<endl;
        print(n-1,t);
        cout<<t<<' '<<n;
    }
    
}