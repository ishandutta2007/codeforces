

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/

////////////////////////////////////////

int main(){
    int n;cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    int count1[n+1],count2[n+1];
    count1[0]=0;count2[0]=0;
    for(int i=1;i<=n;i++){
        count1[i]=count1[i-1];
        count2[i]=count2[i-1];
        if(a[i]==1)count1[i]++;
        else count2[i]++;
    }
    int left[n+2],right[n+2];
    memset(left,0,sizeof(left));memset(right,0,sizeof(right));
    for(int i=1;i<=n;i++){
        left[i]=count1[i-1];
        right[i]=count2[n]-count2[i];
    }
    int b[n+1];
    for(int i=1;i<=n;i++){
        b[i]=a[n+1-i];
    }
    int dp[n+1][n+1][3];memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[j]==1){
                dp[i][j][1]=dp[i][j-1][1]+1;
                dp[i][j][2]=dp[i][j-1][2];
            }else{
                dp[i][j][1]=dp[i][j-1][1];
                dp[i][j][2]=max(dp[i][j-1][2],dp[i][j-1][1])+1;
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j][1]<<" "<<dp[i][j][2]<<endl;
        }
        cout<<endl;
    }*/
/*    for(int i=0;i<=n;i++){
        cout<<left[i]<<" ";
    }cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<right[i]<<" ";
    }cout<<endl;*/
    
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x=left[i]+right[j];
            int plus=max(count1[j]-count1[i-1],count2[j]-count2[i-1]);
            plus=max(plus,dp[n-j+1][n-i+1][1]);
            plus=max(plus,dp[n-j+1][n-i+1][2]);
            ans=max(ans,x+plus);
     /*       cout<<plus<<" "<<x+plus<<endl;*/
        }
       /* cout<<endl;*/
    }
    cout<<ans<<endl;
    return 0;
}