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
typedef pair<dd,dd> d_d;
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
///////////////////////////

ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        i=mod(i);
        if(p==1)return i;
        if(p%2==0)return po(mod(i*i),p/2);
        return mod(i*po(i,p-1));
    }
}
ll bunbo(ll n){
    return po(n,i_5);
}

int main(){fastio
    ll n;
    string s;
    cin>>n;
    cin>>s;
    ll sum[n];
    sum[0]=0;if(s[0]=='0')sum[0]++;
    rep(i,1,n-1){
        sum[i]=sum[i-1];
        if(s[i]=='0')sum[i]++;
    }
    //rep(i,0,n-1)cout<<sum[i]<<" ";cout<<endl;
    ll next[n];next[n-1]=n-1;
    for(ll i=n-2;i>=0;i--){
        next[i]=next[i+1];
        if(s[i]=='0')next[i]=i;
    }
    ll nextg[n];
    rep(i,0,n-1){
        nextg[i]=(next[i]-i)%2;
    }
    ll id[n];ll zs=0;
    rep(i,0,n-1){
        if(s[i]=='0'){
            id[i]=zs;
            zs++;
        }else{
            id[i]=-1;
        }
    }
    ll dis[zs];
    rep(i,0,n-1){
        if(id[i]>=0)dis[id[i]]=i;
    }
    for(ll i=zs-1;i>=1;i--){
        dis[i]=(dis[i]-dis[i-1])%2+2;
    }dis[0]=0;
    //rep(i,0,zs-1)cout<<dis[i];cout<<endl;
    ll roldis[zs];
    ll pri=1009;
    roldis[0]=0;
    rep(i,1,zs-1){
        roldis[i]=mod(roldis[i-1]*pri+dis[i]);
    }
    ll q;cin>>q;
    while(q--){
        ll x,y,l;cin>>x>>y>>l;x--;y--;
        ll zcou,zcou2;
        if(x-1>=0)zcou=sum[x+l-1]-sum[x-1];
        else zcou=sum[x+l-1];
        if(y-1>=0)zcou2=sum[y+l-1]-sum[y-1];
        else zcou2=sum[y+l-1];
        if(zcou!=zcou2){
            cout<<"No"<<endl;continue;
        }
        if(zcou>=1&&nextg[x]!=nextg[y]){
            cout<<"No"<<endl;continue;
        }
        if(zcou<=1){
            cout<<"Yes"<<endl;continue;
        }
        ll xc=id[next[x]];
        ll yc=id[next[y]];
        ll rolx=mod(roldis[xc+zcou-1]-mod(roldis[xc]*po(pri,zcou-1)));
        ll roly=mod(roldis[yc+zcou-1]-mod(roldis[yc]*po(pri,zcou-1)));
        if(mod(rolx-roly)==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}
/*
 13
 1101010010110
 */