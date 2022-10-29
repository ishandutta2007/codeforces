

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
#define n 1000005

int z(int k){
    int res=1;
    while(k>0){
        int y=k%10;
        if(y!=0)res*=y;
        k/=10;
    }
    return res;
}


int main(){
    int q;cin>>q;
    int dp[n+1];
    for(int i=1;i<=9;i++)dp[i]=i;
    for(int i=10;i<=n;i++){
        dp[i]=dp[z(i)];
    }
    int sum[n+1][15];memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=9;j++){
            sum[i][j]=sum[i-1][j];
        }
        sum[i][dp[i]]++;
    }
    while(q--){
        int l,r,k;cin>>l>>r>>k;
        cout<<sum[r][k]-sum[l-1][k]<<endl;
    }
    return 0;
}