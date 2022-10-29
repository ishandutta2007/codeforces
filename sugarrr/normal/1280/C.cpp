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
    ll k;cin>>k;
    ll n=2*k;
    vector<l_l>v[n+1];
    rep(i,1,n-1){
        ll a,b,c;cin>>a>>b>>c;
        v[a].pb(l_l(b,c));
        v[b].pb(l_l(a,c));
    }
    queue<ll>q;
    vector<ll>u;
    vector<l_l>chi[n+1];
    l_l p[n+1];rep(i,1,n)p[i]=l_l(-1,0);
    q.push(1);p[1]=l_l(0,0);
    while(!q.empty()){
        ll t=q.front();q.pop();
        u.pb(t);
        for(auto x:v[t]){
            if(p[x.first].first==-1){
                p[x.first]=l_l(t,x.second);
                chi[t].pb(x);
                q.push(x.first);
            }
        }
    }
    ll dp[n+1];memset(dp,0,sizeof(dp));
    reverse(u.begin(),u.end());
    for(auto t:u){
        dp[t]++;
        for(auto x:chi[t]){
            dp[t]+=dp[x.first];
        }
    }
    ll sum=0;
    rep(i,2,n){
        if(dp[i]%2==1){
            sum+=p[i].second;
        }
    }
    cout<<sum<<" ";
    sum=0;
    rep(i,2,n){
        sum+=min(dp[i],n-dp[i])*p[i].second;
    }
    cout<<sum<<endl;
    
    return 0;
}


int main(){fastio
    
    ll q;cin>>q;
    while(q--){
        anspro();
    }
    
    return 0;
}