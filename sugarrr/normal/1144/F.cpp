
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll n,m;cin>>n>>m;
    vector<l_l>edge;
    vector<ll>v[n];
    rep(i,0,m-1){
        ll a,b;cin>>a>>b;a--;b--;
        edge.pb(l_l(a,b));
        v[a].pb(b);
        v[b].pb(a);
    }
    ll col[n];memset(col,0,sizeof(col));
    queue<ll>q;q.push(0);col[0]=1;
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(col[x]==0){
                col[x]=3-col[t];
                q.push(x);
            }else if(col[x]+col[t]!=3){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    rep(i,0,m-1){
        cout<<(col[edge[i].first]-1);
    }
    cout<<endl;
    
    
    return 0;
}