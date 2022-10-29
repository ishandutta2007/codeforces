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
////////////////////////////


int main(){
    ll n;cin>>n;
    bool a[n][30];memset(a,false,sizeof(a));
    rep(i,0,n-1){
        string s;cin>>s;
        ll len=s.size();
        rep(j,0,len-1){
            ll k=s[j]-'a';
            a[i][k]=true;
        }
    }
    vector<ll>v[n];
    rep(j,0,29){
        ll res=-1;
        rep(i,0,n-1){
            if(a[i][j]){
                if(res==-1){
                    res=i;
                }else{
                    v[res].pb(i);
                    v[i].pb(res);
                }
            }
        }
    }
    /*
    rep(i,0,n-1){
        for(auto x:v[i])cout<<x<<" ";cout<<endl;
    }*/
    bool used[n];memset(used,false,sizeof(used));
    queue<ll>q;
    ll ans=0;
    rep(i,0,n-1){
        if(used[i])continue;
        ans++;
        q.push(i);
        used[i]=true;
        while(!q.empty()){
            ll t=q.front();q.pop();
            for(auto x:v[t]){
                if(used[x]==false){
                    used[x]=true;
                    q.push(x);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}