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
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////


bool anspro(){
    ll n;cin>>n;
    ll row=(n+2)/3;
    ll sum=0;
    ll y=1;
    while(1){
        sum+=y;
        if(sum>=row)break;
        y*=4;
    }
    sum-=y;
    ll a=y+(row-sum)-1;
    if(n%3==1){
        cout<<a<<endl;return 0;
    }
    //cout<<a<<"!"<<endl;
    
    ll b=y*2;
    y/=4;
    while(y>0){
        ll amari=row-sum;
        if(amari<=y){
            
        }else if(amari<=2*y){
            b+=2*y;
            sum+=y;
        }else if(amari<=3*y){
            b+=3*y;
            sum+=2*y;
        }else{
            b+=y;
            sum+=3*y;
        }
        y/=4;
    }
    if(n%3==2){
        cout<<b<<endl;
    }else{
        cout<<(a^b)<<endl;
    }
    
    return 0;
}

int main(){fastio
    ll qu;cin>>qu;
    while(qu--){
        anspro();
    }
    return 0;
}
/*
 10 1 2 3 4 5 6 7 8 9 10
 */