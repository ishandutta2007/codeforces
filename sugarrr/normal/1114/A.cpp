
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
//#define i_7 998244353
//#define i_5 998244351
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-8;
////////////////////////////////////////

void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}

int main(){
    ll x,y,z;cin>>x>>y>>z;
    ll a,b,c;cin>>a>>b>>c;
    if(a<x){
        no();return 0;
    }
    a-=x;
    b=b+a;
    if(b<y){
        no();return 0;
    }
    b-=y;
    c=c+b;
    if(c<z){
        no();return 0;
    }else{
        yes();
    }
    
    return 0;
}