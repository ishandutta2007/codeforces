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
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////
int digit(ll a){
    int c=0;
    while(a>0){
        a/=10;
        c+=1;
    }
    return c;
}

ll calc(ll x){
    if(x==0){
        return 1;
    }
    ll d=digit(x);
   
    int y[d];
    rep(i,0,d-1){
        y[d-1-i]=x%10;
        x/=10;
    }
    
    ll dp[d][2][4];memset(dp,0,sizeof(dp));
    
    if(0<y[0])dp[0][1][0]++;
    else if(0==y[0])dp[0][0][0]++;
    rep(k,1,9){
        if(k<y[0])dp[0][1][1]++;
        else if(k==y[0])dp[0][0][1]++;
    }
    rep(i,0,d-2){
        rep(j,0,3){
            dp[i+1][1][j]+=dp[i][1][j];
        }
        rep(j,0,2){
            dp[i+1][1][j+1]+=9*dp[i][1][j];
        }
        
        if(0<y[i+1]){
            rep(j,0,3)dp[i+1][1][j]+=dp[i][0][j];
        }else{
            rep(j,0,3)dp[i+1][0][j]+=dp[i][0][j];
        }
        rep(k,1,9){
            if(k<y[i+1]){
                rep(j,0,2)dp[i+1][1][j+1]+=dp[i][0][j];
            }else if(k==y[i+1]){
                rep(j,0,2)dp[i+1][0][j+1]+=dp[i][0][j];
            }
        }
    }
    ll ans=0;
    rep(j,0,1){
        rep(k,0,3){
            ans+=dp[d-1][j][k];
        }
    }
    /*cout<<x<<endl;
    rep(i,0,d-1){
        rep(k,0,3){
            rep(j,0,1){
                cout<<dp[i][j][k]<<" ";
            }cout<<endl;
        }cout<<endl;
    }
    cout<<endl;*/
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    //cout<<calc(99999);
    
    //rep(i,9995,10050)cout<<i<<" "<<calc(i)<<endl
    
    ll q;cin>>q;
    while(q--){
        ll l,r;cin>>l>>r;
        ll x=calc(l-1);
        ll y=calc(r);
        /*cout<<x<<endl;
        cout<<y<<endl;*/
        cout<<y-x<<endl;
    }
    
    
    return 0;
    
}