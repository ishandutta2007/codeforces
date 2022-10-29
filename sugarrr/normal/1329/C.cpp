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


#define N (1<<21)+10
ll a[N];

void f(ll i){
    ll left=2*i;
    ll right=2*i+1;
    if(a[left]==0&&a[right]==0){
        a[i]=0;
    }else{
        if(a[left]>a[right]){
            a[i]=a[left];
            f(left);
        }else{
            a[i]=a[right];
            f(right);
        }
    }
}
ll depcal(ll n){
    ll res=0;
    while(n>0){
        n/=2;res++;
    }
    return res;
}
ll func(ll i){
    ll left=2*i;
    ll right=2*i+1;
    if(a[left]==0&&a[right]==0){
        return 1;
    }else{
        if(a[left]>a[right]){
            return 1+func(left);
        }else{
            return 1+func(right);
        }
    }
}

bool anspro(){
    ll h,g;cin>>h>>g;
    rep(i,1,(1<<h)-1)cin>>a[i];
    
    vector<ll>ans;
    rep(i,1,(1<<h)-1){
        if(a[i]==0)continue;
        while(1){
            ll dep=depcal(i);
            ll fun=func(i);
            if(dep+fun<=g+1){
                break;
            }else{
                ans.pb(i);
                f(i);
                //rep(j,1,(1<<h)-1)cout<<a[j]<<" ";cout<<endl;
            }
        }
    }
    ll sum=0;
    rep(i,0,(1<<h)-(1<<g))sum+=a[i];
    cout<<sum<<endl;
    for(auto x:ans)cout<<x<<" ";cout<<endl;
    
    rep(i,1,(1<<h)-1)a[i]=0;
    return 0;
}

int main(){fastio
    
    ll qu;cin>>qu;
    while(qu--){
        anspro();
    }
    
    return 0;
}