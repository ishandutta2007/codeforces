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
    string s,t,p;cin>>s>>t>>p;
    ll ls=s.size(),lt=t.size();
    if(ls>lt)return false;
    ll tpos=0;
    bool uset[lt];memset(uset,false,sizeof(uset));
    bool ok[ls];memset(ok,false,sizeof(ok));
    rep(spos,0,ls-1){
        while(tpos<=lt-1){
            if(s[spos]==t[tpos]){
                uset[tpos]=true;
                tpos++;
                ok[spos]=true;
                break;
            }else{
                tpos++;
            }
        }
    }
    rep(i,0,ls-1){
        if(ok[i]==false)return false;
    }
    
    rep(i,0,p.size()-1){
        rep(j,0,lt-1){
            if(uset[j])continue;
            if(t[j]==p[i]){
                uset[j]=true;
                break;
            }
        }
    }
    rep(i,0,lt-1){
        if(uset[i]==false)return false;
    }
    
    return true;
}


int main(){fastio
    ll t;cin>>t;
    
    while(t--){
        if(anspro())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;;
    }
    
    return 0;
}