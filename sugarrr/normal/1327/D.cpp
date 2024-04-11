#include <bits/stdc++.h>
//#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

vector<ll>ANS;

#define N 200005
ll col[N];

ll cal(vector<ll>& a){
    ll as=a.size();
    vector<ll>div;
    for(ll i=1;i*i<=as;i++){
        if(as%i==0){
            div.pb(i);
            if(i*i!=as)div.pb(as/i);
        }
    }
    SORT(div);
    ll divs=div.size();
    rep(i,0,divs-2){
        ll g=div[i];
        rep(j,0,g-1){
            ll pos=j+g;
            bool flag=true;
            while(pos<=as-1){
                if(col[a[j]]!=col[a[pos]]){
                    flag=false;
                    break;
                }
                pos+=g;
            }
            if(flag)return g;
        }
    }
    return as;
}

bool anspro(){
    ll n;cin>>n;
    ll to[n+1];
    rep(i,1,n)cin>>to[i];
    rep(i,1,n)cin>>col[i];
    ll used[n+1];memset(used,0,sizeof(used));
    ll ans=inf;
    rep(i,1,n){
        if(used[i])continue;
        used[i]=1;
        ll pos=i;
        vector<ll>k;k.pb(i);
        while(1){
            pos=to[pos];
            if(used[pos]==0){
                k.pb(pos);
                used[pos]=1;
            }else{
                break;
            }
        }
        Min(ans,cal(k));
    }
    cout<<ans<<endl;
    return 0;
}

int main(){fastio
    ll nq;cin>>nq;
    while(nq--){
        anspro();
    }
    return 0;
}