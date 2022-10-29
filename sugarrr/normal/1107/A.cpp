
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

void ans(){
    ll n;cin>>n;
    string s;cin>>s;
    if(n>=3){
        cout<<"YES"<<endl<<"2"<<endl;
        cout<<s[0]<<" ";
        rep(i,1,n-1)cout<<s[i];
        cout<<endl;
    }else{
        if(s[0]<s[1]){
            cout<<"YES"<<endl<<"2"<<endl;
            cout<<s[0]<<" "<<s[1]<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int main(){
    ll q;cin>>q;
    while(q--){
        ans();
    }
    
    return 0;
}