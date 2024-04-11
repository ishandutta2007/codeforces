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
///////////////////////////////////////


int main(){fastio
    
    ll n;cin>>n;
    l_l a[n];rep(i,0,n-1){cin>>a[i].first;a[i].second=i+1;}
    sort(a,a+n);
    if(n<=3){
        cout<<1<<endl;
        return 0;
    }
    if(a[0].first==a[n-1].first){
        cout<<1<<endl;
        return 0;
    }
    ll same=a[2].first-a[1].first;
    bool flag=true;
    rep(i,1,n-2){
        if(same!=a[i+1].first-a[i].first){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<a[0].second<<endl;return 0;
    }
    flag=true;
    same=a[1].first-a[0].first;
    rep(i,0,n-3){
        if(same!=a[i+1].first-a[i].first){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<a[n-1].second<<endl;return 0;
    }
    
    vector<ll>v;
    rep(i,0,n-2){
        v.pb(a[i+1].first-a[i].first);
    }
    sort(v.begin(),v.end());
    if(v[0]==v[v.size()-1]){
        cout<<1<<endl;
        return 0;
    }
    
    ll x=v[v.size()-1];
    if(v[0]+v[1]==x&&v[2]==x){
        vector<ll>q;
        rep(i,0,n-2){
            if(a[i+1].first-a[i].first!=x){
                q.pb(a[i+1].second);
                q.pb(a[i].second);
            }
        }
        sort(q.begin(),q.end());
        if(q.size()==0){
            cout<<1<<endl;
        }else if(q.size()==2){
            cout<<q[0]<<endl;
        }else if(q.size()==4){
            rep(i,0,2){
                rep(j,i+1,3){
                    if(q[i]==q[j]){
                        cout<<q[i]<<endl;
                        return 0;
                    }
                }
            }
        }else{
            cout<<-1<<endl;
        }
    }else{
        cout<<-1<<endl;
    }
    
    return 0;
}