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


#define M 2520
int main(){fastio
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll to[n*M];
    rep(i,0,n-1){
        ll m;cin>>m;
        ll b[m];rep(j,0,m-1){cin>>b[j];b[j]--;}
        rep(j,0,M-1){
            ll st=i*M+j;
            ll c=(j+a[i]);
            ll k=c%m;if(k<0)k+=m;
            ll t=c%M;if(t<0)t+=M;
            ll go=b[k]*M+t;
            to[st]=go;
        }
    }
    
    //rep(i,0,n*M-1)cout<<i<<":"<<to[i]<<endl;cout<<endl;
    
    ll ans[n*M];memset(ans,0,sizeof(ans));
    rep(i,0,n*M-1){
        if(ans[i]!=0)continue;
        set<ll>s;
        ll pos=i;s.insert(pos);
        while(1){
            pos=to[pos];
            if(s.find(pos)!=s.end()){
                set<ll>v;
                ll now=pos;
                do{
                    v.insert(now/M);
                    now=to[now];
                }while(now!=pos);
                ll k=v.size();
                for(auto x:s){
                    ans[x]=k;
                }
                break;
            }else if(ans[pos]!=0){
                ll k=ans[pos];
                for(auto x:s){
                    ans[x]=k;
                }
                break;
            }else{
                s.insert(pos);
            }
        }
    }
    /*
    rep(i,0,n*M-1){
        cout<<ans[i]<<endl;
    }cout<<endl;*/
    ll q;cin>>q;
    while(q--){
        ll x,y;cin>>x>>y;x--;
        y=y%M;if(y<0)y+=M;
        cout<<ans[x*M+y]<<endl;
    }
    
    
    return 0;
}