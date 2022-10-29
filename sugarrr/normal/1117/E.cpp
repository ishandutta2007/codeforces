
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
////////////////////////////////////////
ll n;
void asc(string s){
    cout<<"? ";
    rep(i,0,n-1)cout<<s[i];
    cout<<endl;
    fflush(stdout);
}
void answer(string s){
    cout<<"! "<<s<<endl;
    fflush(stdout);
}
#define M 25

int main(){
    string s;cin>>s;
    n=s.size();
    string t1,t2,t3;
    rep(i,0,M-1){
        rep(j,0,M-1){
            rep(k,0,M-1){
                t1+=('a'+i);
            }
        }
    }
    rep(i,0,M-1){
        rep(j,0,M-1){
            rep(k,0,M-1){
                t2+=('a'+j);
            }
        }
    }
    rep(i,0,M-1){
        rep(j,0,M-1){
            rep(k,0,M-1){
                t3+=('a'+k);
            }
        }
    }
    string u1,u2,u3;
    asc(t1);cin>>u1;
    asc(t2);cin>>u2;
    asc(t3);cin>>u3;
    ll ans[n];
    rep(i,0,n-1){
        ll k1=u1[i]-'a';
        ll k2=u2[i]-'a';
        ll k3=u3[i]-'a';
        ans[i]=k1*M*M+k2*M+k3;
    }
    ll rev[n];
    rep(i,0,n-1){
        rev[ans[i]]=i;
    }
    string fina;
    rep(i,0,n-1){
        fina+=s[rev[i]];
    }
    answer(fina);
    
    return 0;
}