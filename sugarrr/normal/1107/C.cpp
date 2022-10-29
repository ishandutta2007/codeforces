
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-8;
////////////////////////////////////////



int main(){
    ll n,k;cin>>n>>k;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    string s;cin>>s;
    ll pos=0;
    ll ans=0;
    while(pos<=n-1){
        vector<ll>v;
        v.pb(a[pos]);
        while(pos!=n-1&&s[pos]==s[pos+1]){
            v.pb(a[pos+1]);
            pos++;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ll sv=v.size();
        for(ll i=0;i<=min(k-1,sv-1);i++){
            ans+=v[i];
        }
        pos++;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}