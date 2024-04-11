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

ll n,k;

void query(set<ll>v){
    cout<<"? ";
    for(auto x:v){
        cout<<x<<" ";
    }cout<<endl;
    fflush(stdout);
}
void last(ll m){
    cout<<"! ";
    cout<<m<<endl;
    fflush(stdout);
}

int main(){fastio
    cin>>n>>k;
    ll a[n];memset(a,-1,sizeof(a));
    if(n>=2*k-1){
        set<ll>s;
        rep(i,1,k)s.insert(i);
        ll pos[k],val[k];
        rep(i,0,k-1){
            query(s);
            cin>>pos[i]>>val[i];
            s.erase(pos[i]);
            s.insert(k+i+1);
        }
        sort(val,val+k);
        set<ll>p;rep(i,0,k-1)p.insert(pos[i]);
        query(p);
        ll deb,va;cin>>deb>>va;
        ll po=lower_bound(val,val+k,va)-val+1;
        last(po);
        return 0;
    }else{
        set<ll>s;
        rep(i,1,k)s.insert(i);
        ll pos[n-k+1],val[n-k+1];
        rep(i,0,n-k){
            query(s);
            cin>>pos[i]>>val[i];
            s.erase(pos[i]);
            s.insert(k+i+1);
        }
        vector<ll>kn,un;
        rep(i,1,n){
            bool fl=true;
            rep(j,0,n-k){
                if(pos[j]==i){
                    kn.pb(i);fl=false;break;
                }
            }
            if(fl)un.pb(i);
        }
        ll csma=0,clar=0;
        rep(i,0,k-2){
            set<ll>s;
            s.insert(pos[0]);s.insert(pos[1]);
            rep(j,0,k-2){
                if(i==j)continue;
                s.insert(un[j]);
            }
            query(s);
            ll deb,va;cin>>deb>>va;
            if(va==val[0])csma++;
            else if(va==val[1])clar++;
            else{
                va=va/0;
                deb/=0;
                return 0;
            }
        }
        if(val[0]>val[1])swap(csma,clar);
        last(clar+1);
        return 0;
        
    }
    
    return 0;
}