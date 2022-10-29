

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
#define rep(i,l,r) for(int i=l;i<=r;i++)
const double EPS=1E-8;

////////////////////////////////////////




int main() {
    int n,m,k;cin>>n>>m>>k;
    char t[n][m+1];
    rep(i,0,n-1)cin>>t[i];
    int sum=0;
    int a[n][500];rep(i,0,n-1)rep(j,0,499)a[i][j]=0;
    rep(i,0,n-1){
        int b[500];memset(b,0,sizeof(b));
        int c=0;
        rep(j,0,m-1){
            if(t[i][j]=='1'){
                b[c]=j;
                c++;
            }
        }
        if(c==0)continue;
        rep(j,0,c-1){
            int mi=inf;
            rep(q,0,j){
                if(mi>b[c-1-(j-q)]-b[q]+1)mi=b[c-1-(j-q)]-b[q]+1;
            }
            a[i][j]=mi;
        }a[i][c]=0;
        sum+=b[c-1]-b[0]+1;
    }
    /*rep(i,0,n-1){
        rep(j,0,10){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }*/
    
    int dp[n+1][k+1];
    rep(i,0,n)rep(j,0,k)dp[i][j]=sum;
    dp[0][0]=0;
    rep(i,0,n-1){
        rep(j,0,k){
            rep(l,0,j){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j-l]+a[i][l]);
            }
        }
    }
    /*rep(i,0,n){
        rep(j,0,k){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    */
    cout<<dp[n][k]<<endl;
    return 0;
}