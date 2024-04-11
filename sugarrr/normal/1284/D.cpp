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
#define fi first
#define se second
////////////////////////////

ll n;
bool check(vector<l_l>&a,vector<l_l>&b){
    vector<l_l>fir,sec;
    rep(i,0,n-1){
        fir.pb(l_l(a[i].fi,i));
        sec.pb(l_l(a[i].se,i));
    }
    sort(fir.begin(),fir.end());
    sort(sec.begin(),sec.end());
    multiset<ll>bfi,bse;
    ll secpos=0;
    rep(i,0,n-1){
        ll anum=fir[i].se;
        bfi.insert(b[anum].fi);
        bse.insert(b[anum].se);
        while(secpos<=n-1){
            if(sec[secpos].fi<fir[i].fi){
                ll bnum=sec[secpos].se;
                auto itr=bfi.lower_bound(b[bnum].fi);
                bfi.erase(itr);
                itr=bse.lower_bound(b[bnum].se);
                bse.erase(itr);
                secpos++;
            }else{
                break;
            }
        }
        ll x=(*bfi.rbegin());
        ll y=(*bse.begin());
        if(x>y){
            return false;
        }
    }
    return true;
}

int main(){fastio
    cin>>n;
    vector<l_l>a(n),b(n);
    rep(i,0,n-1){
        cin>>a[i].fi>>a[i].se>>b[i].fi>>b[i].se;
    }
    if(!check(a,b)){
        cout<<"NO"<<endl;return 0;
    }
    if(!check(b,a)){
        cout<<"NO"<<endl;return 0;
    }
    cout<<"YES"<<endl;
    
    
    return 0;
}
/*
 3
 5 10 1001 1004
 3 5 1004 1006
 1 7 1004 1008
 */