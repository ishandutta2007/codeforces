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
#define fi first
#define se second
////////////////////////////

void no(){
    cout<<"NO"<<endl;
}

int main(){fastio
    
    ll n;cin>>n;
    ll p[n+1],c[n+1];
    rep(i,1,n)cin>>p[i]>>c[i];
    vector<ll>chi[n+1];
    queue<ll>q;
    vector<ll>idx;
    ll root=-1;
    rep(i,1,n){
        if(p[i]==0){
            q.push(i);
            root=i;
        }else{
            chi[p[i]].pb(i);
        }
    }
    while(!q.empty()){
        ll t=q.front();q.pop();idx.pb(t);
        for(auto x:chi[t]){
            q.push(x);
        }
    }
    vector<ll>v[n+1];
    reverse(idx.begin(),idx.end());
    /*
    rep(i,1,n){
        cout<<i<<":";
        for(auto x:chi[i])cout<<x<<" ";cout<<endl;
    }*/
    for(auto pos:idx){
        if(chi[pos].size()==0){
            v[pos].pb(pos);
            if(c[pos]>0){
                no();return 0;
            }
            continue;
        }
        for(auto c:chi[pos]){
            for(auto x:v[c]){
                v[pos].pb(x);
            }
        }
        ll vs=v[pos].size();
        if(c[pos]>vs){
            no();return 0;
        }
        v[pos].insert(v[pos].begin()+c[pos],pos);
    }
    ll ans[n+1];
    ll count=1;
    for(auto x:v[root]){
        ans[x]=count;
        count++;
    }
    cout<<"YES"<<endl;
    rep(i,1,n){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}