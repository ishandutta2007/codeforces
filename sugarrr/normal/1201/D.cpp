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

struct row{
    ll pos;
    ll l,r;
};
#define Q 200005
ll b[Q];ll q;
ll cal(ll s,ll t){
    if(s>t)swap(s,t);
    ll res=inf;
    ll p1=lower_bound(b,b+q,s)-b;
    ll p2=upper_bound(b,b+q,t)-b;
    if(p1!=p2){
        return t-s;
    }
    if(p1!=q){
        Min(res,2*b[p1]-s-t);
    }
    p1--;
    if(p1>=0){
        Min(res,t+s-2*b[p1]);
    }
    
    return res;
}

int main(){fastio
    ll n,m,k;cin>>n>>m>>k>>q;
    l_l tr[k];rep(i,0,k-1)cin>>tr[i].first>>tr[i].second;
    sort(tr,tr+k);
    vector<row>v;
    ll po=0;
    while(po<=k-1){
        ll ro=tr[po].first;
        ll le=tr[po].second;
        ll ri=le;
        while(po<=k-2&&tr[po].first==tr[po+1].first){
            ri=tr[po+1].second;
            po++;
        }
        row res;
        res.pos=ro;
        res.l=le;
        res.r=ri;
        v.pb(res);
        po++;
    }
    rep(i,0,q-1)cin>>b[i];
    sort(b,b+q);
    
    ll vs=v.size();
    ll dp[vs+1][2];
    rep(i,0,vs-1)rep(j,0,1)dp[i][j]=inf;
    if(v[0].pos==1){
        dp[1][1]=v[0].r-1;
    }else{
        ll dif=v[0].r-v[0].l;
        dp[1][0]=dif+cal(1,v[0].r);
        dp[1][1]=dif+cal(1,v[0].l);
    }
    rep(i,1,vs-1){
        ll dif=v[i].r-v[i].l;
        Min(dp[i+1][0],dif+dp[i][0]+cal(v[i-1].l,v[i].r));
        Min(dp[i+1][0],dif+dp[i][1]+cal(v[i-1].r,v[i].r));
        Min(dp[i+1][1],dif+dp[i][0]+cal(v[i-1].l,v[i].l));
        Min(dp[i+1][1],dif+dp[i][1]+cal(v[i-1].r,v[i].l));
    }
    /*rep(i,1,vs){
        rep(j,0,1){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;*/
    
    ll ans=v[vs-1].pos-1;
    ans+=min(dp[vs][0],dp[vs][1]);
    cout<<ans<<endl;
    
    return 0;
}