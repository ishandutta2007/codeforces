
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
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
long double EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////////////////


int main(){fastio;
    ll k;cin>>k;
    vector<ll>ans;
    /*if(k<=1500){
        ll x=4000-k;
        ll sum=x-(k+x)/2000;
        rep(i,1,999){
            ans.pb(0);ans.pb(-1);
        }
        sum-=999;
        ans.pb(-sum);
        ans.pb(x);
    }else*/{
        ll x=1000000-k%2000;
        ll sum=x-(k+x)/2000;
        rep(i,1,1998){
            ans.pb(0);
        }
        ans.pb(-sum);ans.pb(x);
    }
    /*ll a[2001];rep(i,1,2000)a[i]=ans[i-1];a[0]=0;
    rep(i,1,1999)a[i+1]+=a[i];
    ll mx=0;
    rep(l,0,1999){
        rep(r,l,1999){
            ll sum=a[r+1]-a[l];
            if(sum*(r-l+1)==502515108){
                cout<<l<<" "<<r<<endl;
            }
            Max(mx,sum*(r-l+1));
        }
    }
    cout<<mx<<endl;*/
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    return 0;
}