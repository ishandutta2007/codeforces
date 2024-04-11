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
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

ll d[10]={119,18,93,91,58,107,111,82,127,123};

ll hen(string s){
    ll c=0;
    rep(i,0,6){
        c+=(s[6-i]-'0')*(1ll<<i);
    }
    return c;
}

int main(){fastio
    
    
    ll n,k;cin>>n>>k;
    string S[n];rep(i,0,n-1)cin>>S[i];
    ll a[n];rep(i,0,n-1)a[i]=hen(S[i]);
    
    
    ll ep[128][10];
    rep(i,0,127){
        if(i==18){
            
        };
        
        rep(z,0,9){
            bool f=true;
            ll j=d[z];
            ll cnt=0;
            rep(k,0,6){
                ll x=(i>>k)&1;
                ll y=(j>>k)&1;
                if(x==1&&y==0)f=false;
                if(x==0&&y==1)cnt++;
            }
            if(f)ep[i][z]=cnt;
            else ep[i][z]=inf;
        }
    }
    
    
    bool dp[n+1][k+1];memset(dp,false,sizeof(dp));
    dp[n][0]=true;
    for(ll i=n;i>=1;i--){
        rep(j,0,k){
            if(dp[i][j]==false)continue;
            rep(x,0,9){
                if(j+ep[a[i-1]][x]<=k)dp[i-1][j+ep[a[i-1]][x]]=true;
            }
        }
    }
    /*
    rep(i,0,n){
        rep(j,0,k){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }*/
    if(dp[0][k]==false){
        cout<<-1<<endl;return 0;
    }
    string ans;
    ll j=k;
    rep(i,0,n-1){
        for(ll x=9;x>=0;x--){
            ll res=ep[a[i]][x];
            if(res==inf)continue;
            if(j-res>=0&&dp[i+1][j-res]){
                ans+=(char)('0'+x);
                j=j-res;
                break;
            }
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}
/*
 1110111
 0010010
 1011101
 1011011
 0111010
 1101011
 1101111
 1010010
 1111111
 1111011
 */