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
///////////////////////////////////

int main(){
    ll b,k;cin>>b>>k;
    ll a[k];rep(i,0,k-1)cin>>a[i];
    if(k==1){
        if(a[k-1]%2==0){
            cout<<"even"<<endl;
        }else{
            cout<<"odd"<<endl;
        }
    }else{
        if(b%2==0){
            if(a[k-1]%2==0){
                cout<<"even"<<endl;
            }else{
                cout<<"odd"<<endl;
            }
        }else{
            ll m=0;
            rep(i,0,k-1){
                m+=(a[i]%2);
            }
            if(m%2==0)cout<<"even"<<endl;
            else cout<<"odd"<<endl;
        }
    }
    return 0;
}