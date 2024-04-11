//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

//////////////////////////


ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
ll h,w;

bool valid(ll a,ll b){
    if(0<=a&&a<=h-1&&0<=b&&b<=w-1)return true;
    return false;
}
int main(){fastio
    cin>>h>>w;
    string s[h];rep(i,0,h-1)cin>>s[i];
    
    ll Cnt=0;
    rep(i,0,h-1){
        rep(j,0,w-1){
            if(s[i][j]=='#')Cnt++;
        }
    }
    if(Cnt==0){
        cout<<0<<endl;return 0;
    }
    bool c1=true,c2=true;
    rep(i,0,h-1){
        ll f=true;
        rep(j,0,w-1){
            if(s[i][j]=='#')f=false;
        }
        if(f)c1=false;
    }
    rep(j,0,w-1){
        ll f=true;
        rep(i,0,h-1){
            if(s[i][j]=='#')f=false;
        }
        if(f)c2=false;
    }
    if(c1^c2){
        cout<<-1<<endl;return 0;
    }
    
    rep(i,0,h-1){
        ll flag=0;
        rep(j,0,w-1){
            if(s[i][j]=='.'){
                if(flag==1)flag=2;
            }else{
                if(flag==0)flag=1;
                else if(flag==2){
                    cout<<-1<<endl;return 0;
                }
            }
        }
    }
    rep(j,0,w-1){
        ll flag=0;
        rep(i,0,h-1){
            if(s[i][j]=='.'){
                if(flag==1)flag=2;
            }else{
                if(flag==0)flag=1;
                else if(flag==2){
                    cout<<-1<<endl;return 0;
                }
            }
        }
    }
    bool used[h][w];memset(used,false,sizeof(used));
    ll ans=0;
    rep(i,0,h-1){
        rep(j,0,w-1){
            if(used[i][j])continue;
            if(s[i][j]=='.')continue;
            queue<l_l>q;
            q.push({i,j});
            used[i][j]=true;
            while(!q.empty()){
                l_l t=q.front();q.pop();
                rep(z,0,3){
                    ll nx=t.fi+dx[z];
                    ll ny=t.se+dy[z];
                    if(valid(nx,ny)){
                        if(used[nx][ny])continue;
                        if(s[nx][ny]=='.')continue;
                        q.push({nx,ny});
                        used[nx][ny]=true;
                    }
                }
            }
            ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}