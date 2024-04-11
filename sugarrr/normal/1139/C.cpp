
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

ll po(ll n,ll k){
    if(k==0)return 1;
    if(k==1)return n;
    if(k%2==0)return mod(po(mod(n*n),k/2));
    return mod(po(n,k-1)*n);
}

int main(){
    ll n,k;cin>>n>>k;
    vector<ll>v[n];
    rep(i,1,n-1){
        ll a,b,c;cin>>a>>b>>c;a--;b--;
        if(c==1)continue;
        v[a].pb(b);
        v[b].pb(a);
    }
    bool used[n];memset(used,false,sizeof(used));
    ll ans=po(n,k);
    rep(i,0,n-1){
        if(!used[i]){
            ll count=1;
            queue<ll>q;
            q.push(i);
            used[i]=true;
            while(!q.empty()){
                ll t=q.front();q.pop();
                for(auto x:v[t]){
                    if(used[x])continue;
                    used[x]=true;
                    count++;
                    q.push(x);
                }
            }
            Add(ans,-po(count,k));
        }
    }
    cout<<mod(ans)<<endl;
    
    return 0;
}