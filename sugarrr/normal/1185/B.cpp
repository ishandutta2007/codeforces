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

void yes(){
    cout<<"YES"<<endl;
}
void no(){
    cout<<"NO"<<endl;
}
vector<pair<string,ll>>ca(string s){
    vector<pair<string,ll>> v;
    ll n=s.size();
    ll pos=0;
    while(pos<=n-1){
        ll c=1;
        while(pos<=n-2&&s[pos]==s[pos+1]){
            c++;pos++;
        }
        string a;a+=s[pos];
        v.pb(pair<string,ll>(a,c));
        pos++;
    }
    //rep(i,0,v.size()-1){cout<<v[i].first<<" "<<v[i].second<<endl;}
    
    return v;
}

bool ansp(){
    string a,b;cin>>a>>b;
    vector<pair<string,ll>>va,vb;
    
    
    
    va=ca(a);
    vb=ca(b);
    
    ll vas=va.size();
    if(va.size()!=vb.size()){
        no();return 0;
    }
    rep(i,0,vas-1){
        if(va[i].first!=vb[i].first){
            no();return 0;
        }
        if(va[i].second>vb[i].second){
            no();return 0;
        }
    }
    yes();
    
    return 0;
}

int main(){fastio
    
    ll n;cin>>n;
    while(n--){
        ansp();
        
    }
    
    return 0;
}