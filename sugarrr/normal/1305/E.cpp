//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
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
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
///////////////////////////

ll n,m;

bool check(){
    ll sum=0;
    rep(i,3,n){
        sum+=(i-1)/2;
    }
    if(sum<m){
        return false;
    }
    return true;
}
int main(){fastio
    cin>>n>>m;
    if(n<=2){
        if(m==0){
            rep(i,1,n)cout<<i<<" ";
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
        return 0;
    }
    if(check()==false){
        cout<<-1<<endl;return 0;
    }
    ll sum=0;
    ll p=1;
    ll add=0;
    while(1){
        if(sum+p*2<=m){
            sum=sum+p*2;
            p++;
        }else{
            if(sum==m)add=0;
            else if(sum+p<m)add=2;
            else add=1;
            break;
        }
    }
    p--;
    ll a=2*p;
    ll b=n-a-add;
    ll sta=b-1;
    if(add==0){
        rep(i,0,n-1)cout<<sta+i<<" ";
        cout<<endl;return 0;
    }
    ll ans[n];
    rep(i,0,n-2){
        ans[i]=sta+i;
    }
    ll cou[n];
    ll x=ans[1];
    sum=0;
    rep(i,0,n-2){
        if(i<x)cou[i]=0;
        else cou[i]=(i+2-x)/2;
        sum+=cou[i];
    }
    ll res=m-sum;
    ans[n-1]=ans[n-2]+ans[n-2-2*res+1];
    rep(i,0,n-1)cout<<ans[i]<<" ";cout<<endl;
    
    
    return 0;
}