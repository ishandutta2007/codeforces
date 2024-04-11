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
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


//////////////////////////////////////


int main(){
    int n;cin>>n;
    ll a[2][n+1];rep(i,0,1)rep(j,0,n-1)cin>>a[i][j+1];a[0][0]=0;a[1][0]=0;
    ll sum1[n+1],sum2[n+1],sum3[n+1],sumr[n+1];
    rep(i,0,n)sum1[i]=sum2[i]=sum3[i]=sumr[i]=0;
    
    rep(i,1,n){
        sum1[i]=sum1[i-1];
        if(i%2==1){
            sum1[i]+=(2*i-2)*a[0][i];
            sum1[i]+=(2*i-1)*a[1][i];
        }else{
            sum1[i]+=(2*i-1)*a[0][i];
            sum1[i]+=(2*i-2)*a[1][i];
        }
    }
    rep(i,1,n){
        sum2[i]=sum2[i-1];
        sum2[i]+=a[0][i]*(i-1)+a[1][i]*(2*n-i);
    }
    rep(i,1,n){
        sum3[i]=sum3[i-1];
        sum3[i]+=a[0][i]*(2*n-i)+a[1][i]*(i-1);
    }
    sumr[n]=a[0][n]+a[1][n];
    for(int i=n-1;i>=1;i--){
        sumr[i]=sumr[i+1];
        sumr[i]+=a[0][i]+a[1][i];
    }
    
    ll ans=0;
    rep(k,0,n-1){
        ll sum=sum1[k];
        if(k%2==0){
            sum+=sum2[n]-sum2[k];
            sum+=sumr[k+1]*k;
        }else{
            sum+=sum3[n]-sum3[k];
            sum+=sumr[k+1]*k;
        }
        ans=max(ans,sum);
    }
    
    
    cout<<ans<<endl;
    return 0;
}