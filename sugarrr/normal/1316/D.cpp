//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
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
typedef pair<dd,dd> d_d;
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
///////////////////////////

#define N 1005
ll n;
ll dx[4]={1,0,0,-1};
ll dy[4]={0,1,-1,0};
string dir="DRLUX";
ll ans[N][N];
l_l fin[N][N];
bool valid(ll x,ll y){
    if(1<=x&&x<=n&&1<=y&&y<=n)return true;
    return false;
}
int main(){fastio
    cin>>n;
    rep(i,1,n)rep(j,1,n)ans[i][j]=-1;
    rep(i,1,n)rep(j,1,n)cin>>fin[i][j].fi>>fin[i][j].se;
    
    rep(i,1,n)rep(j,1,n){
        if(fin[i][j]==l_l(i,j)){
            ans[i][j]=4;
            queue<l_l>q;
            q.push(l_l(i,j));
            while(!q.empty()){
                l_l t=q.front();q.pop();
                rep(k,0,3){
                    ll nx=t.fi+dx[k];
                    ll ny=t.se+dy[k];
                    if(!valid(nx,ny))continue;
                    if(ans[nx][ny]!=-1)continue;
                    if(fin[nx][ny]==l_l(i,j)){
                        q.push(l_l(nx,ny));
                        ans[nx][ny]=3-k;
                    }
                }
            }
        }
    }
    rep(i,1,n)rep(j,1,n){
        if(ans[i][j]==-1&&fin[i][j].fi!=-1){
            cout<<"INVALID"<<endl;return 0;
        }
    }
    
    rep(i,1,n)rep(j,1,n){
        if(ans[i][j]==-1){
            bool fl=false;
            queue<l_l>q;q.push(l_l(i,j));
            rep(k,0,3){
                ll nx=i+dx[k];
                ll ny=j+dy[k];
                if(valid(nx,ny)){
                    if(ans[nx][ny]==-1){
                        q.push({nx,ny});
                        ans[i][j]=k;
                        ans[nx][ny]=3-k;
                        fl=true;
                        break;
                    }
                }
            }
            if(!fl){
                cout<<"INVALID"<<endl;return 0;
            }
            while(!q.empty()){
                l_l t=q.front();q.pop();
                rep(k,0,3){
                    ll nx=t.fi+dx[k];
                    ll ny=t.se+dy[k];
                    if(!valid(nx,ny))continue;
                    if(ans[nx][ny]!=-1)continue;
                    
                    q.push(l_l(nx,ny));
                    ans[nx][ny]=3-k;
                
                }
            }
        }
    }
    cout<<"VALID"<<endl;
    rep(i,1,n){
        rep(j,1,n){
            cout<<dir[ans[i][j]];
        }cout<<endl;
    }
    
    return 0;
}