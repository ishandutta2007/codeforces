#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
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

int main(){
    ll N=2000;
    bool prime[N];memset(prime,true,sizeof(prime));
    rep(i,2,N-1){
        for(ll j=2;j*j<=i;j++){
            if(i%j==0)prime[i]=false;
        }
    }
    /*
    rep(i,3,1000){
        bool fl=false;
        rep(j,i,3*i/2){
            if(prime[j])fl=true;
        }
        if(!fl)cout<<i<<endl;
    }
    cout<<"end"<<endl;*/
    
    ll n;cin>>n;
    rep(j,n,3*n/2){
        if(prime[j]){
            cout<<j<<endl;
            rep(i,1,n){
                if(i!=n)cout<<i<<" "<<i+1<<endl;
                else cout<<n<<" "<<1<<endl;
            }
            j-=n;
            ll pos=1;
            while(j--){
                cout<<pos<<" "<<pos+n/2<<endl;
                pos++;
            }
            return 0;
        }
    }
    
    
    return 0;
}