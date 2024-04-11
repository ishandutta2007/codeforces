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


int main(){fastio
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    string dp[2];
    dp[0]=s;
    dp[1]=s;
    ll cnt=0;
    ll day=0;
    while(1){
        ll p=0;
        rep(i,0,n-1){
            if(i<=n-2&&dp[day&1][i]=='R'&&dp[day&1][i+1]=='L'){
                p++;
                dp[(day+1)&1][i]='L';
                dp[(day+1)&1][i+1]='R';
                i++;
            }else{
                dp[(day+1)&1][i]=dp[day&1][i];
            }
        }
        if(p==0)break;
        cnt+=p;
        day++;
        //cout<<dp[day&1]<<endl;
    }
    if(k<day||cnt<k){cout<<-1<<endl;return 0;}
    ll DAY=day;
    //ll CNT=cnt;
    dp[0]=s;
    dp[1]=s;
    day=0;
    cnt=0;
    bool FLAG=false;
    while(1){
        ll p=0;
        vector<ll>v;
        rep(i,0,n-1){
            if(i<=n-2&&dp[day&1][i]=='R'&&dp[day&1][i+1]=='L'){
                p++;
                dp[(day+1)&1][i]='L';
                dp[(day+1)&1][i+1]='R';
                v.pb(i+1);
                i++;
            }else{
                dp[(day+1)&1][i]=dp[day&1][i];
            }
        }
        if(p==0)break;
        if(!FLAG){
            if(cnt+p+DAY-day-1>k){
                FLAG=true;
                ll kai=k-(cnt+DAY-day-1);
                rep(i,0,kai-1){
                    if(i!=kai-1)cout<<"1 "<<v[i]<<endl;
                    else{
                        cout<<p-i<<" ";
                        rep(j,i,p-1)cout<<v[j]<<" ";
                        cout<<endl;
                    }
                }
            }else{
                if(cnt+p+DAY-day-1==k)FLAG=true;
                for(auto x:v)cout<<"1 "<<x<<endl;
            }
        }else{
            cout<<p<<" ";
            for(auto x:v)cout<<x<<" ";
            cout<<endl;
        }
        
        cnt+=p;
        day++;
        //cout<<dp[day&1]<<endl;
    }
    
    return 0;
}