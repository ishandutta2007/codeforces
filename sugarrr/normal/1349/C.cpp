//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
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

ll h,w;
bool valid (ll a,ll b){
    if(0<=a&&a<=h-1&&0<=b&&b<=w-1)return true;
    return false;
}
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};


struct Que{
    ll x,y,p;
    ll num;
};
bool comp(Que a,Que b){
    return a.p<b.p;
}
int main(){fastio
    ll t;
    cin>>h>>w>>t;
    
    ll s[h][w];
    string inp[h];
    rep(i,0,h-1)cin>>inp[i];
    rep(i,0,h-1)rep(j,0,w-1)s[i][j]=inp[i][j]-'0';
    ll kai[h][w];memset(kai,-1,sizeof(kai));
    queue<l_l>p;
    rep(i,0,h-1)rep(j,0,w-1){
        rep(x,0,3){
            ll nx=i+dx[x];
            ll ny=j+dy[x];
            if(valid(nx,ny)){
                if(s[i][j]==s[nx][ny])kai[i][j]=1;
            }
        }
        if(kai[i][j]!=-1)p.push({i,j});
    }
    if(p.empty()){
        rep(i,0,t-1){
            ll x,y,p;cin>>x>>y>>p;x--;y--;
            cout<<s[x][y]<<endl;
        }
        
        return 0;
        
    }
    
    
    while(!p.empty()){
        l_l t=p.front();p.pop();
        ll i=t.fi;ll j=t.se;
        rep(x,0,3){
            ll nx=i+dx[x];
            ll ny=j+dy[x];
            if(valid(nx,ny)){
                if(kai[nx][ny]==-1){
                    p.push({nx,ny});
                    kai[nx][ny]=kai[i][j]+1;
                }
            }
        }
    }
    //rep(i,0,h-1){rep(j,0,w-1)cout<<kai[i][j]<<" ";cout<<endl;}
    
    rep(i,0,t-1){
        ll x,y,p;cin>>x>>y>>p;x--;y--;
        if(p<kai[x][y])cout<<s[x][y]<<endl;
        else{
            ll t=s[x][y]+p-kai[x][y]+1;
            cout<<t%2<<endl;
        }
    }
    
    /*
    sort(q,q+t,comp);
    ll pos=0;
    ll ans[t];
    /*
    rep(i,0,h-1){
        rep(j,0,w-1)cout<<s[0][i][j]<<" ";cout<<endl;
    }*/
    
    //ll N=1000000;
    /*
    ll N=10;
    rep(cnt,1,N){
        
        rep(i,0,h-1){
            rep(j,0,w-1)cout<<s[(cnt-1)&1][i][j]<<" ";cout<<endl;
        }cout<<endl;
        
        bool f=true;
        rep(i,0,h-1)rep(j,0,w-1){
            bool sm=false;
            rep(x,0,3){
                ll nx=i+dx[x];
                ll ny=j+dy[x];
                if(valid(nx,ny)){
                    if(s[(cnt-1)&1][nx][ny]==s[(cnt-1)&1][i][j])sm=true;
                }
            }
            
            if(sm){
                if(s[cnt&1][i][j]!=1-s[(cnt-1)&1][i][j])f=false;
                s[cnt&1][i][j]=1-s[(cnt-1)&1][i][j];
            }
            else{
                if(s[cnt&1][i][j]!=s[(cnt-1)&1][i][j])f=false;
                s[cnt&1][i][j]=s[(cnt-1)&1][i][j];
            }
        }
        
        if(f){
            while(pos<=t-1){
                ans[q[pos].num]=s[q[pos].p&1][q[pos].x][q[pos].y];
                pos++;
            }
            break;
        }
        
        while(pos<=t-1&&q[pos].p==cnt){
            ans[q[pos].num]=s[cnt&1][q[pos].x][q[pos].y];
            pos++;
        }
        if(pos==t)break;
         
        
    }*/
    
    
    return 0;
}