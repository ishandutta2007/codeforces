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
#define endl "\n"  //
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


ll n,m;
bool valid(ll i,ll j){
    if(0<=i&&i<=n-1&&0<=j&&j<=m-1)return true;
    return false;
}

#define N 255
ll yo[N][N];
ll ta[N][N];
ll ans[N][N];
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

bool no[N][N];
int main(){fastio
    cin>>n>>m;
    ll z[n][m];rep(i,0,n-1)rep(j,0,m-1)cin>>z[i][j];
    vector<ll>a(n),b(m);
    rep(i,0,n-1)a[i]=0;
    rep(i,0,m-1)b[i]=0;
    rep(i,0,n-1){
        rep(j,0,m-1)chmax(a[i],z[i][j]);
        rep(j,0,m-1)chmax(b[j],z[i][j]);
    }
    ll c[n*m+1];memset(c,0,sizeof(c));
    rep(i,0,n-1)c[a[i]]++;
    rep(i,0,m-1)c[b[i]]+=2;
    vector<ll>d,e,f;
    rep(i,1,n*m){
        if(c[i]==0)continue;
        if(c[i]==3)d.pb(i);
        else if(c[i]==1)e.pb(i);
        else if(c[i]==2)f.pb(i);
    }
    SORT(d);SORT(e);SORT(f);
    reverse(all(e));reverse(all(f));
    memset(ans,-1,sizeof(ans));
    ll ds=d.size();
    
    l_l mp[n*m+1];rep(i,1,n*m)mp[i]={-1,-1};
    
    rep(i,0,ds-1){
        ans[i][i]=d[i];
        mp[d[i]]={i,i};
    }
    rep(i,ds,n-1){
        ans[i][ds-1]=e[i-ds];
        mp[e[i-ds]]={i,ds-1};
    }
    rep(i,ds,m-1){
        ans[ds-1][i]=f[i-ds];
        mp[f[i-ds]]={ds-1,i};
    }
    
    /*
    rep(i,0,n-1){
        rep(j,0,m-1)cout<<ans[i][j]<<" ";cout<<endl;
    }
     */
    memset(no,false,sizeof(no));
    rep(i,1,n*m){
        if(mp[i].fi!=-1){
            no[mp[i].fi][mp[i].se]=true;
        }
    }
    queue<l_l>q;
    rrep(i,n*m,1){
        
        if(mp[i].fi==-1){
            l_l t;
            while(1){
                t=q.front();q.pop();
                if(ans[t.fi][t.se]==-1)break;
            }
            ans[t.fi][t.se]=i;
            
            ll x=t.fi;
            ll y=t.se;
            for(ll j=-1;j<=1;j+=2){
                ll nx=x+j;
                if(valid(nx,y)){
                    if(no[nx][y])continue;
                    ta[nx][y]++;
                    if(yo[nx][y])q.push({nx,y});
                }
            }
            for(ll j=-1;j<=1;j+=2){
                ll ny=y+j;
                if(valid(x,ny)){
                    if(no[x][ny])continue;
                    yo[x][ny]++;
                    if(ta[x][ny])q.push({x,ny});
                }
            }
            
        }else{
            ll x=mp[i].fi;
            ll y=mp[i].se;
            for(ll j=-1;j<=1;j+=2){
                ll nx=x+j;
                if(valid(nx,y)){
                    if(no[nx][y])continue;
                    ta[nx][y]++;
                    if(yo[nx][y])q.push({nx,y});
                }
            }
            for(ll j=-1;j<=1;j+=2){
                ll ny=y+j;
                if(valid(x,ny)){
                    if(no[x][ny])continue;
                    yo[x][ny]++;
                    if(ta[x][ny])q.push({x,ny});
                }
            }
        }
    }
    rep(i,0,n-1){
        rep(j,0,m-1)cout<<ans[i][j]<<" ";cout<<endl;
    }
    
    return 0;
}