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
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////

int main(){fastio
    
    ll n,m;cin>>n>>m;
    vector<ll>v[n+1];
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll used[n+1];memset(used,0,sizeof(used));
    ll sz=1;
    rep(i,1,n){
        if(used[i]!=0)continue;
        vector<ll>q;q.pb(i);
        used[i]=sz;
        while(!q.empty()){
            vector<ll>nex;
            ll f[n+1];
            rep(i,1,n){
                if(used[i]==0)f[i]=0;
                else f[i]=inf;
            }
            for(auto x:q){
                for(auto y:v[x]){
                    f[y]++;
                }
            }
            ll qs=q.size();
            rep(i,1,n){
                if(f[i]<qs){
                    nex.pb(i);
                    used[i]=sz;
                }
            }
            swap(q,nex);
        }
        sz++;
    }
    //rep(i,1,n)cout<<used[i]<<" ";cout<<endl;
    sort(used+1,used+n+1);
    
    vector<ll>ans;
    rep(i,1,n){
        ll c=1;
        while(i<=n-1&&used[i]==used[i+1]){
            i++;c++;
        }
        ans.pb(c);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";cout<<endl;
    
    return 0;
}
/*
 
 
 5 8
 1 2
 1 3
 1 4
 1 5
 2 3
 2 4
 2 5
 3 4
 */