//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

/*
#include "boost/multiprecision/cpp_int.hpp"
#include "boost/multiprecision/cpp_dec_float.hpp"
namespace mp = boost::multiprecision;
typedef mp::cpp_int LL;
typedef mp::number<mp::cpp_dec_float<1024>> DD;// 1024(TLE)
*/
 
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
#define rrep(i,r,l) for(ll i=r;i>=l;i--)
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
//#define endl "\n"  //
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T,class S>
inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T,class S>
inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

void mod_print(ll k){
    ll P=50000;
    rep(y,1,P){
        ll x=mod(y*k);
        
        if(abs(x)<=P||x+P>=i_7){
            if(x+P>=i_7){
                x-=i_7;
            }
            cout<<x<<"/"<<y<<endl;
            //cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
typedef vector<ll> vl;
//////////////////////////


bool anspro(){
    ll n,x,y;cin>>n>>x>>y;
    ll b[n];rep(i,0,n-1)cin>>b[i];
    priority_queue<l_l>q;
    vector<ll>v[n+2];
    rep(i,0,n-1)v[b[i]].pb(i);
    rep(i,1,n+1){
        if(v[i].size()>=1){
            q.push({v[i].size(),i});
        }
    }
    ll debri=1;
    rep(i,1,n+1){
        if(v[i].size()==0){
            debri=i;break;
        }
    }
    
    ll pos[n+2];memset(pos,0,sizeof(pos));
    ll ans[n];memset(ans,-1,sizeof(ans));
    rep(zz,1,x){
        l_l t=q.top();q.pop();
        ans[v[t.se][pos[t.se]]]=0;
        pos[t.se]++;
        if(t.fi==1)continue;
        q.push({t.fi-1,t.se});
    }
    
    ll mx=0;
    rep(i,1,n+1)chmax(mx,v[i].size()-pos[i]);
    ll t=n-x-mx;
    
    if(y-x>2*t){
        cout<<"NO"<<endl;return 0;
    }else cout<<"YES"<<endl;
    
    vector<l_l>cyc;
    rep(i,1,n+1){
        ll cnt=0;
        ll vis=v[i].size();
        rep(j,pos[i],vis-1){
            cnt++;
            if(cnt>t){
                ans[v[i][j]]=debri;
            }else{
                cyc.pb({v[i][j],b[v[i][j]]});
            }
        }
    }
    ll cs=cyc.size();
    ll CNT=0;
    rep(i,0,cs-1){
        CNT++;
        if(CNT>y-x){
            ans[cyc[i].fi]=debri;
        }else{
            ans[cyc[i].fi]=cyc[(i+cs/2)%cs].se;
        }
    }
    rep(i,0,n-1)if(ans[i]==0)ans[i]=b[i];
    
    rep(i,0,n-1)cout<<ans[i]<<" ";cout<<endl;
    
    return 0;
}

int main(){fastio
    
    ll que;cin>>que;
    while(que--){
        anspro();
    }
    
    return 0;
}