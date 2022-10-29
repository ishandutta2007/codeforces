

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


int main(){
    ll n,k;cin>>n>>k;
    ll a[n+1][2];a[0][0]=0;a[0][1]=0;
    rep(i,1,n)cin>>a[i][0];
    rep(i,1,n)cin>>a[i][1];
    ll ans=0;
    ll sum[n+1];memset(sum,0,sizeof(sum));
    rep(i,1,n){
        if(a[i][1]==1){
            ans+=a[i][0];
        }
    }
    rep(i,1,n){
        if(a[i][1]==1){
            sum[i]=sum[i-1];
        }else{
            sum[i]=sum[i-1]+a[i][0];
        }
    }
    ll max=0;
    rep(i,k,n){
        if(max<sum[i]-sum[i-k])max=sum[i]-sum[i-k];
    }
    cout<<max+ans<<endl;
    return 0;
}