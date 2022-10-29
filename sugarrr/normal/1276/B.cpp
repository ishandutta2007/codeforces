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


void anspro(){
    ll n,m,a,b;cin>>n>>m>>a>>b;
    vector<ll>v[n+1];
    rep(i,1,m){
        ll c,d;cin>>c>>d;
        v[c].pb(d);
        v[d].pb(c);
    }
    queue<ll>q;
    bool used[n+1];memset(used,false,sizeof(used));
    ll rev[n+1];memset(rev,-1,sizeof(rev));
    q.push(a);used[a]=true;
    ll in[n+1];memset(in,0,sizeof(in));
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(x==b){
                ll pos=t;
                while(pos!=a){
                    if(in[pos]!=0)break;
                    in[pos]=1;
                    pos=rev[pos];
                }
            }else if(used[x]==false){
                q.push(x);
                used[x]=true;
                rev[x]=t;
            }
        }
    }
    while(!q.empty())q.pop();
    rep(i,1,n){
        if(i==a||i==b)in[i]=2;
        else if(in[i]!=0)q.push(i);
    }
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(x==a||x==b)continue;
            if(in[x]!=0)continue;
            in[x]=1;
            q.push(x);
        }
    }
    while(!q.empty())q.pop();
    q.push(a);
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(in[x]==0){
                in[x]=3;
                q.push(x);
            }
        }
    }
    ll s3=0,s0=0;
    rep(i,1,n){
        if(in[i]==0)s0++;
        else if(in[i]==3)s3++;
    }
    cout<<s3*s0<<endl;
}


int main(){fastio
    ll n;cin>>n;
    while(n--){
        anspro();
    }
    
    return 0;
}