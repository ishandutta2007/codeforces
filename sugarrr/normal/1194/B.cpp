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




int main(){fastio
    ll t;cin>>t;
    
    while(t--){
        ll h,w;cin>>h>>w;
        string s[h];rep(i,0,h-1)cin>>s[i];
        ll ans=0;
        
        ll mi=inf;
        vector<ll>p;
        rep(i,0,h-1){
            ll c=0;
            rep(j,0,w-1)if(s[i][j]=='.')c++;
            if(mi>c){
                p.clear();
                p.pb(i);
            }else if(mi==c){
                p.pb(i);
            }
            Min(mi,c);
        }
        ans+=mi;
        mi=inf;
        rep(j,0,w-1){
            ll c=0;
            
            bool flag=false;
            rep(i,0,h-1){
                if(s[i][j]=='.'){
                    c++;
                }
            }
            for(auto i:p){
                if(s[i][j]=='.')flag=true;
            }
            if(flag)c--;
            Min(mi,c);
        }
        ans+=mi;
        cout<<ans<<endl;
    }
    
    return 0;
}