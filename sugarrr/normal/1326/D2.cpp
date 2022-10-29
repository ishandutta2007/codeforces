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
#define endl "\n"
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

/*
bool parin(string s){
    ll n=s.size();
    ll pi=0,pj=n-1;
    while(pi<=pj){
        if(s[pi]==s[pj]){
            pi++;pj--;
        }else{
            return false;
        }
    }
    return true;
}

ll cal(string s){
    ll n=s.size();
    for(ll i=n-1;i>=0;i--){
        string t;
        rep(j,0,i)t+=s[j];
        if(parin(t)){
            return i+1;
        }
    }
    return 0;
}*/


ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        i=mod(i);
        if(p==1)return i;
        if(p%2==0)return po(mod(i*i),p/2);
        return mod(i*po(i,p-1));
    }
}
ll bunbo(ll n){
    return po(n,i_5);
}

ll p1=1009;
ll cal(string s){
    ll n=s.size();
    ll a[n+1],b[n+1];
    a[0]=0;
    rep(i,1,n){
        a[i]=mod(a[i-1]*p1+s[i-1]);
    }
    b[n]=0;
    for(ll i=n-1;i>=0;i--){
        b[i]=mod(b[i+1]*p1+s[i]);
    }
    for(ll i=n-1;i>=0;i--){
        ll x=mod(a[i+1]-a[0]);
        ll y=mod(b[0]-b[i+1]*po(p1,i+1));
        if(mod(x-y)==0)return i+1;
    }
    return 0;
}

bool anspro(){
    string s;cin>>s;
    ll n=s.size();
    ll pi=0,pj=n-1;
    string ini;
    while(pi<pj){
        if(s[pi]==s[pj]){
            ini+=s[pi];
            pi++;pj--;
        }
        else break;
    }
    string t;
    rep(i,pi,pj)t+=s[i];
    ll m1=cal(t);
    reverse(t.begin(),t.end());
    ll m2=cal(t);
    if(m2>m1){
        swap(m1,m2);
    }else{
        reverse(t.begin(),t.end());
    }
    string mid;
    rep(i,0,m1-1){
        mid+=t[i];
    }
    string inirev=ini;
    reverse(inirev.begin(),inirev.end());
    cout<<ini<<mid<<inirev<<endl;
    
    return 0;
}

int main(){fastio
    
    ll que;cin>>que;
    while(que--){
        anspro();
    }
    
    return 0;
}