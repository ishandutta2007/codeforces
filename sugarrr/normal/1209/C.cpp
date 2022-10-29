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
bool ansproblem(){
    ll n;cin>>n;
    string s;cin>>s;
    ll a[n+2];
    rep(i,0,n-1){
        a[i+1]=s[i]-'0';
    }
    
    ll ans[n+2];memset(ans,0,sizeof(ans));
    ll ma=0;
    vector<ll>v;
    ans[0]=1;a[0]=0;v.pb(0);
    bool df=true;
    rep(i,1,n){
        if(ma>a[i]){
            ans[i]=1;
            v.pb(i);
            df=false;
        }
        Max(ma,a[i]);
    }
    if(df){
        rep(i,0,n-1)cout<<1;cout<<endl;
        return 0;
    }
    ll vs=v.size();
    ll f2=-1;
    rep(i,0,vs-2){
        ll t1=v[i],t2=v[i+1];
        rep(j,t1+1,t2-1){
            if(a[t1]<=a[j]&&a[j]<=a[t2]){
                ans[j]=1;
            }else{
                ans[j]=2;
                if(f2==-1)f2=a[j];
            }
        }
    }
    rep(j,v[vs-1]+1,n){
        ans[j]=2;
    }
    ll now=0;
    rep(i,1,n){
        if(ans[i]==1){
            if(now>a[i]){
                cout<<"-"<<endl;return 0;
            }else{
                now=a[i];
            }
        }
    }
    rep(i,1,n){
        if(ans[i]==2){
            if(now>a[i]){
                cout<<"-"<<endl;return 0;
            }else{
                now=a[i];
            }
        }
    }
    rep(i,1,n){
        cout<<ans[i];
    }
    cout<<endl;
    
    return 0;
}

int main(){fastio
    ll q;cin>>q;
    while(q--){
        ansproblem();
    }
    
    return 0;
}