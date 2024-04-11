
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
void no(){
    cout<<"No"<<endl;
}
void yes(){
    cout<<"Yes"<<endl;
}

int main(){
    string s,t;cin>>s>>t;
    ll n=s.size(),m=t.size();
    string v="aiueo";
    if(n!=m){
        no();return 0;
    }
    bool a[n],b[n];memset(a,false,sizeof(a));memset(b,false,sizeof(b));
    rep(i,0,n-1){
        rep(j,0,4){
            if(s[i]==v[j])a[i]=true;
            if(t[i]==v[j])b[i]=true;
        }
    }
    /*rep(i,0,n-1){
        cout<<a[i]<<" "<<b[i]<<endl;
    }*/
    rep(i,0,n-1){
        if(a[i]^b[i]){
            no();return 0;
            
        }
    }
    yes();
    return 0;
}