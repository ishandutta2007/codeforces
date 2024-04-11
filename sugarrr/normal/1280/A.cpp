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
//void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////

bool anspro(){
    ll n;cin>>n;
    string s;cin>>s;
    ll len=s.size();
    bool f=false;
    rep(i,0,n-1){
        ll k=s[i]-'0';
        if(f||len>n){
            f=true;
            len+=mod((len-i-1)*(k-1));
        }else{
            string t=s.substr(i+1,len-i-1);
            rep(j,1,k-1){
                s+=t;
            }
            len=s.size();
            if(len>n)f=true;
        }
    }
    cout<<mod(len)<<endl;
    
    return 0;
}


int main(){fastio
    
    ll q;cin>>q;
    while(q--){
        anspro();
    }
    
    return 0;
}