#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;

#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////



bool anspro(){
    ll n,k;cin>>n>>k;
    if(k%3!=0){
        if(n%3==0)return false;
        else return true;
    }else{
        n%=(k+1);
        if(n%3==0&&n!=k)return false;
        return true;
    }
    
}


int main(){fastio
    ll n=100;
    ll k=3;
    bool dp[n];memset(dp,0,sizeof(dp));
    rep(i,0,n-1){
        if(i-1>=0&&dp[i-1]==false)dp[i]=true;
        if(i-2>=0&&dp[i-2]==false)dp[i]=true;
        if(i-k>=0&&dp[i-k]==false)dp[i]=true;
    }
    /*rep(i,0,n-1){
        cout<<i<<" "<<dp[i]<<endl;
    }*/
    
    ll t;cin>>t;
    while(t--){
        if(anspro())cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;;
    }
    
    return 0;
}