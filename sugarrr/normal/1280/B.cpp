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
    ll h,w;cin>>h>>w;
    string s[h];rep(i,0,h-1)cin>>s[i];
    ll ca=0,cp=0;
    rep(i,0,h-1)rep(j,0,w-1){
        if(s[i][j]=='A')ca++;
        else cp++;
    }
    if(ca==0){
        cout<<"MORTAL"<<endl;return 0;
    }
    if(cp==0){
        cout<<0<<endl;return 0;
    }
    bool s1=1,s2=1;
    rep(i,0,h-1){
        if(s[i][0]=='P')s1=0;
        if(s[i][w-1]=='P')s2=0;
    }
    if(s1||s2){
        cout<<1<<endl;return 0;
    }
    s1=1;s2=1;
    rep(j,0,w-1){
        if(s[0][j]=='P')s1=0;
        if(s[h-1][j]=='P')s2=0;
    }
    if(s1||s2){
        cout<<1<<endl;return 0;
    }
    bool s3=0;
    if(s[0][0]=='A'||s[0][w-1]=='A'||s[h-1][0]=='A'||s[h-1][w-1]=='A')s3=1;
    if(s3){
        cout<<2<<endl;return 0;
    }
    rep(i,0,h-1){
        bool f=true;
        rep(j,0,w-1){
            if(s[i][j]=='P')f=false;
        }
        if(f){
            cout<<2<<endl;return 0;
        }
    }
    rep(j,0,w-1){
        bool f=true;
        rep(i,0,h-1){
            if(s[i][j]=='P')f=false;
        }
        if(f){
            cout<<2<<endl;return 0;
        }
    }
    
    
    rep(i,0,h-1){
        if(s[i][0]=='A'||s[i][w-1]=='A'){
            cout<<3<<endl;return 0;
        }
    }
    rep(j,0,w-1){
        if(s[0][j]=='A'||s[h-1][j]=='A'){
            cout<<3<<endl;return 0;
        }
    }
    cout<<4<<endl;
    
    return 0;
}


int main(){fastio
    
    ll q;cin>>q;
    while(q--){
        anspro();
    }
    
    return 0;
}