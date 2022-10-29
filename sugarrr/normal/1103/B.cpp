
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


void que(ll x,ll y){
    cout<<"? "<<x<<" "<<y<<endl;
    fflush(stdout);
}
void ans(ll ans){
    cout<<"! "<<ans<<endl;
    fflush(stdout);
}


int main(){
    while(1){
        string s;cin>>s;
        string ret;
        if(s[0]=='e')break;
        bool flag=false;
        rep(i,0,1){
            que(i,i+1);
            cin>>ret;
            if(ret[0]=='x'){
                ans(i+1);
                flag=true;
                break;
            }
        }
        if(flag)continue;
        
        ll l=3,r=1000000000;
        while(1){
            if(2*(l-1)>2000000000)break;
            que(l-1,2*(l-1));
            cin>>ret;
            if(ret[0]=='x'){
                r=2*l-2;
                break;
            }else{
                l=2*l-1;
            }
        }
        while(l<r){
            ll m=(l+r)/2;
            que(l-1,m);
            cin>>ret;
            if(ret[0]=='x'){
                r=m;
            }else{
                l=m+1;
            }
        }
        ans(l);
        
    }
    
    return 0;
}