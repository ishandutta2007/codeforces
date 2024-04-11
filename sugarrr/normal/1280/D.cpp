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
void Max(l_l &pos,l_l val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);

void print(l_l a){
    cout<<a.first<<""<<a.second<<" ";
}
bool anspro(){
    ll n,m;cin>>n>>m;
    ll a[n+1],b[n+1];
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    rep(i,1,n)a[i]=b[i]-a[i];
    vector<ll>vec[n+1];
    rep(i,1,n-1){
        ll x,y;cin>>x>>y;
        vec[x].pb(y);vec[y].pb(x);
    }
    ll par[n+1];memset(par,-1,sizeof(par));
    par[1]=0;
    vector<ll>chi[n+1];
    queue<ll>q;q.push(1);
    vector<ll>v;
    while(!q.empty()){
        ll t=q.front();q.pop();
        v.pb(t);
        for(auto x:vec[t]){
            if(par[x]==-1){
                par[x]=t;
                q.push(x);
                chi[t].pb(x);
            }
        }
    }
    reverse(v.begin(),v.end());
    ll sz[n+1];
    for(auto x:v){
        sz[x]=1;
        for(auto y:chi[x]){
            sz[x]+=sz[y];
        }
    }
    //rep(i,1,n)cout<<sz[i]<<" ";cout<<endl;
    //for(auto x:v)cout<<x<<" ";cout<<endl;
    l_l dp[n+1][n+1];
    rep(i,0,n)rep(j,0,n)dp[i][j]=l_l(-inf,-inf);
    for(auto t:v){
        if(chi[t].size()==0){
            dp[t][0]=l_l(0,a[t]);
            continue;
        }
        ll cs=chi[t].size();
        l_l ep[2][sz[t]+1];
        rep(i,0,1)rep(j,0,sz[t])ep[i][j]=l_l(-inf,-inf);
        ep[0][0]=l_l(0,a[t]);
        rep(i,0,cs-1){
            rep(j,0,sz[t]){
                if(ep[i&1][j].first<=-inf/2)break;
                ll pos=chi[t][i];
                rep(k,0,sz[pos]-1){
                    if(j+k<=sz[t]){
                        Max(ep[(i+1)&1][j+k],l_l(ep[i&1][j].first+dp[pos][k].first,ep[i&1][j].second+dp[pos][k].second));
                    }
                    if(j+k+1<=sz[t]){
                        ll c=0;if(dp[pos][k].second>0)c++;
                        Max(ep[(i+1)&1][j+k+1],l_l(ep[i&1][j].first+dp[pos][k].first+c,ep[i&1][j].second));
                    }
                }
            }
            rep(j,0,sz[t])ep[i&1][j]=l_l(-inf,-inf);
        }
        rep(j,0,sz[t]){
            dp[t][j]=ep[cs&1][j];
        }
    }
    /*
    rep(i,1,n){
        rep(j,0,n){
            print(dp[i][j]);
        }cout<<endl;
    }
     */
    ll ans=dp[1][m-1].first;
    if(dp[1][m-1].second>0)ans++;
    cout<<ans<<endl;
    return 0;
}


int main(){fastio
    
    ll q;cin>>q;
    while(q--){
        anspro();
    }
    
    return 0;
}