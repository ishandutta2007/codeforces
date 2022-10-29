//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
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
#define fi first
#define se second
////////////////////////////

ll N;
bool anspro(){
    ll n,x;cin>>n>>x;
    N=n+5;
    string s;cin>>s;
    ll c[n];
    c[0]=N;
    if(s[0]=='0')c[0]++;
    else c[0]--;
    rep(i,1,n-1){
        c[i]=c[i-1];
        if(s[i]=='0')c[i]++;
        else c[i]--;
    }
    ll las=c[n-1];
    ll t[N*2];memset(t,0,sizeof(t));
    rep(i,0,n-1){
        t[c[i]]++;
    }
    if(las==N){
        if(N+x<0||2*N-1<N+x)cout<<0<<endl;
        else if(t[N+x]==0)cout<<0<<endl;
        else cout<<-1<<endl;
        return 0;
    }
    ll ans=0;
    if(las-N>0){
        ll res=las-N;
        ll kp=((N+x)-(2*N-1))/res;
        ll sta=(N+x);
        if(kp>=3)sta=(N+x)-res*(kp-3);
        for(ll pos=sta;pos>=0;pos-=res){
            if(0<=pos&&pos<=2*N-1)ans+=t[pos];
        }
    }else{
        ll res=N-las;
        ll kp=(0-(N+x))/res;
        ll sta=N+x;
        if(kp>=3)sta+=res*(kp-3);
        for(ll pos=sta;pos<=2*N-1;pos+=res){
            if(0<=pos&&pos<=2*N-1)ans+=t[pos];
        }
    }
    if(x==0)ans++;
    cout<<ans<<endl;
    
    return 0;
}


int main(){fastio
    
    ll t;cin>>t;
    while(t--){
        anspro();
    }
    
    return 0;
}