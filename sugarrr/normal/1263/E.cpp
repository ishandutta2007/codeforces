#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
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
////////////////////////////
//
struct RMQRAQ{
    ll n;
    vector<ll>data,lazy;
    RMQRAQ(ll vs){
        n=1;
        while(n<vs)n*=2;
        data.resize(2*n-1,0);
        lazy.resize(2*n-1,0);
    }
    void eval(ll k,ll l,ll r){
        if(lazy[k]!=0){
            data[k]+=lazy[k];
            if(r-l>1){
                lazy[2*k+1]+=lazy[k];
                lazy[2*k+2]+=lazy[k];
            }
            lazy[k]=0;
        }
    }
    void add(ll a,ll b,ll x,ll k,ll l,ll r){
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            lazy[k]+=x;
            eval(k,l,r);
        }else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            data[k]=min(data[2*k+1],data[2*k+2]);
        }
    }
    void add(ll a,ll b,ll x){add(a,b,x,0,0,n);}//[a,b)x
    ll query(ll a,ll b,ll k,ll l,ll r){
        eval(k,l,r);
        if(r<=a||b<=l)return inf;
        if(a<=l&&r<=b){
            return data[k];
        }else{
            ll vl=query(a,b,2*k+1,l,(l+r)/2);
            ll vr=query(a,b,2*k+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
    ll query(ll a,ll b){return query(a,b,0,0,n);}//[a,b)
};
//////////////////////////////////////////////////////
//
struct RBQRAQ{
    ll n;
    vector<ll>data,lazy;
    RBQRAQ(ll vs){
        n=1;
        while(n<vs)n*=2;
        data.resize(2*n-1,0);
        lazy.resize(2*n-1,0);
    }
    void eval(ll k,ll l,ll r){
        if(lazy[k]!=0){
            data[k]+=lazy[k];
            if(r-l>1){
                lazy[2*k+1]+=lazy[k];
                lazy[2*k+2]+=lazy[k];
            }
            lazy[k]=0;
        }
    }
    void add(ll a,ll b,ll x,ll k,ll l,ll r){
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            lazy[k]+=x;
            eval(k,l,r);
        }else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            data[k]=max(data[2*k+1],data[2*k+2]);
        }
    }
    void add(ll a,ll b,ll x){add(a,b,x,0,0,n);}//[a,b)x
    ll query(ll a,ll b,ll k,ll l,ll r){
        eval(k,l,r);
        if(r<=a||b<=l)return -inf;
        if(a<=l&&r<=b){
            return data[k];
        }else{
            ll vl=query(a,b,2*k+1,l,(l+r)/2);
            ll vr=query(a,b,2*k+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }
    ll query(ll a,ll b){return query(a,b,0,0,n);}//[a,b)
};
//////////////////////////////////////////////////////

int main(){fastio
    ll n;cin>>n;
    string s;cin>>s;
    ll N=0;
    ll count=0;
    rep(i,0,n-1){
        if(s[i]=='R'){
            count++;
            Max(N,count);
        }else if(s[i]=='L'){
            count--;
            if(count<0)count=0;
        }
    }
    N+=3;
    RMQRAQ u1(N);
    RBQRAQ u2(N);
    ll a[N];memset(a,0,sizeof(a));
    ll pos=0;
    ll ans=0;
    ll sum=0;
    vector<ll>last;
    rep(i,0,n-1){
        if(s[i]=='L'){
            pos--;
            if(pos<0)pos=0;
        }else if(s[i]=='R'){
            pos++;
        }else{
            ll po;
            if(s[i]=='('){
                po=1;
            }else if(s[i]==')'){
                po=-1;
            }else{
                po=0;
            }
            ll dis=po-a[pos];
            sum+=dis;
            if(dis!=0){
                a[pos]=po;
                u1.add(pos,N,dis);
                u2.add(pos,N,dis);
                if(sum!=0){
                    ans=-1;
                }else if(u1.query(0,N)<0){
                    ans=-1;
                }else{
                    ans=u2.query(0,N);
                }
            }
        }
        last.pb(ans);
    }
    for(auto x:last)cout<<x<<" ";
    return 0;
}