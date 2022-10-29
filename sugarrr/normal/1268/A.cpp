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

int main(){fastio
    
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    cout<<n<<endl;
    ll pos=k;
    while(1){
        if(s[pos]<s[pos-k]){
            rep(i,0,n-1){
                cout<<s[i%k];
            }
            return 0;
        }else if(s[pos]==s[pos-k]){
            pos++;
        }else{
            break;
        }
        if(pos==n){
            cout<<s<<endl;return 0;
        }
    }
    pos=k-1;
    while(pos>=0){
        if(s[pos]=='9')pos--;
        else break;
    }
    rep(i,0,n-1){
        ll j=i%k;
        if(j<pos)cout<<s[j];
        else if(j==pos)cout<<((s[j]-'0')+1);
        else cout<<0;
    }
    cout<<endl;
    
    return 0;
}