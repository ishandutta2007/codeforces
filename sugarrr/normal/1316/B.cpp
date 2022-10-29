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
struct obj{
    string s;ll id;
};
bool compb(obj a,obj b){
    if(a.s==b.s)return a.id<b.id;
    return a.s<b.s;
}
 
bool anspro(){
    ll n;cin>>n;
    string x;cin>>x;
    vector<obj>v;
    rep(k,1,n){
        string s;
        rep(i,k-1,n-1)s+=x[i];
        if((n-k)%2==0){
            for(ll i=k-2;i>=0;i--)s+=x[i];
        }else{
            rep(i,0,k-2)s+=x[i];
        }
        //rep(i,0,n-1)cout<<b[i]<<" ";cout<<endl;
        //cout<<s<<endl;
        v.pb({s,k});
    }
    sort(v.begin(),v.end(),compb);
    cout<<v[0].s<<endl<<v[0].id<<endl;
    return 0;
}
 
int main(){fastio
    /*
    ll n=10;
    ll a[n];rep(i,0,n-1)a[i]=i+1;
    rep(k,1,n){
        cout<<k<<":";
        ll b[n];rep(i,0,n-1)b[i]=a[i];
        rep(i,0,n-k){
            reverse(b+i,b+i+k);
        }
        rep(i,0,n-1)cout<<b[i]<<" ";cout<<endl;
    }*/
    
    ll q;cin>>q;
    while(q--){
        anspro();
    }
    
    return 0;
}
/*
int main(){fastio
    ll n,m,p;cin>>n>>m>>p;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll b[m];rep(i,0,m-1)cin>>b[i];
    
    
    return 0;
}
*/