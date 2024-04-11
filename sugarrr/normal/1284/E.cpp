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

ll cal(ll n){
    if(n<=1)return 0;
    else{
        return n*(n-1)/2;
    }
}

dd PI=acos((dd)-1);

int main(){fastio
    //cout<<setprecision(30)<<PI;
    ll n;cin>>n;
    dd x[n],y[n];rep(i,0,n-1)cin>>x[i]>>y[i];
    ll res=0;
    rep(i,0,n-1){
        vector<dd>v;
        rep(j,0,n-1){
            if(i==j)continue;
            dd res=atan2(y[j]-y[i],x[j]-x[i]);
            v.pb(res);
            v.pb(res+PI*2);
        }
        sort(v.begin(),v.end());
        /*
        for(auto x:v)cout<<x<<endl;
        cout<<endl;*/
        ll sum=0;
        rep(j,0,n-2){
            ll p=lower_bound(v.begin(),v.end(),v[j]+PI)-v.begin()-j-1;
            sum+=cal(p);
        }
        sum=(n-1)*(n-2)*(n-3)/6-sum;
        //cout<<sum<<endl;
        res+=sum*(n-4);
    }
    cout<<res/2<<endl;
    return 0;
}