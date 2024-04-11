#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_int
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////


int main(){
    ll n,m;cin>>n>>m;
    vector<ll>s[m];
    rep(i,0,n-1){
        ll a,r;cin>>a>>r;
        a--;
        s[a].pb(r);
    }
    rep(i,0,m-1){
        sort(s[i].begin(),s[i].end());
        reverse(s[i].begin(),s[i].end());
    }
    ll maxsize=0;
    rep(i,0,m-1){
        ll k=s[i].size();
        maxsize=max(maxsize,k);
        if(k>=2){
            rep(j,0,k-2){
                s[i][j+1]+=s[i][j];
            }
        }
    }
    /*rep(i,0,m-1){
        for(auto x:s[i])cout<<x<<" ";
        cout<<endl;
    }*/
    
    ll t[maxsize];memset(t,0,sizeof(t));

    rep(i,0,m-1){
        ll k=s[i].size();
        if(k>=1){
            rep(j,0,k-1){
                if(s[i][j]>0)t[j]+=s[i][j];
            }
        }
    }
    ll ans=0;
    rep(i,0,maxsize-1)ans=max(ans,t[i]);
    cout<<ans<<endl;
    return 0;
}