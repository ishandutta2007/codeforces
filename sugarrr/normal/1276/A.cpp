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
////////////////////////////


string twone="twone";
string two="two";
string one="one";

void anspro(){
    string s;cin>>s;
    ll n=s.size();
    bool era[n];memset(era,false,sizeof(era));
    rep(i,0,n-5){
        bool flag=true;
        rep(j,0,4){
            if(s[i+j]!=twone[j])flag=false;
        }
        if(flag)era[i+2]=true;
    }
    rep(i,0,n-3){
        bool flag=true;
        rep(j,0,2){
            if(s[i+j]!=one[j])flag=false;
            if(era[i+j])flag=false;
        }
        if(flag)era[i+1]=true;
    }
    rep(i,0,n-3){
        bool flag=true;
        rep(j,0,2){
            if(s[i+j]!=two[j])flag=false;
            if(era[i+j])flag=false;
        }
        if(flag)era[i+1]=true;
    }
    ll sum=0;
    rep(i,0,n-1)if(era[i])sum++;
    cout<<sum<<endl;
    rep(i,0,n-1)if(era[i])cout<<i+1<<" ";cout<<endl;
}


int main(){fastio
    ll n;cin>>n;
    while(n--){
        anspro();
    }
    
    return 0;
}