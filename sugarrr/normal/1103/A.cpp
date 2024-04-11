
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
    string s;cin>>s;
    ll n=s.size();
    ll c1=0;
    ll c2=0;
    rep(i,0,n-1){
        if(s[i]=='0'){
            if(c1%2==1){
                cout<<"3 1"<<endl;
            }else{
                cout<<"1 1"<<endl;
            }
            c1++;
        }else{
            if(c2%2==1){
                cout<<"4 1"<<endl;
            }else{
                cout<<"4 3"<<endl;
            }
            c2++;
        }
    }
    
    return 0;
}