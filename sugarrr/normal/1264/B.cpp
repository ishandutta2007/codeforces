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

void yes(){
    cout<<"YES"<<endl;
}
void no(){
    cout<<"NO"<<endl;
}
#define N 200000
ll ans[N];
ll n;
bool check(){
    rep(i,0,n-2){
        if(abs(ans[i]-ans[i+1])!=1)return false;
    }
    return true;
}


int main(){fastio
    ll a,b,c,d;cin>>a>>b>>c>>d;
    if(b==0){
        if(a==0){
            if(abs(c-d)<=1){
                yes();
                if(c<d){
                    rep(i,1,c)cout<<3<<" "<<2<<" ";
                    cout<<3<<endl;
                }else{
                    rep(i,1,d)cout<<2<<" "<<3<<" ";
                    if(c>d)cout<<2<<endl;
                }
            }else{
                no();
            }
            return 0;
        }else if(c!=0||d!=0){
            no();return 0;
        }else{
            if(a==1){
                yes();
                cout<<0<<endl;
            }else no();
        }
        return 0;
    }
    if(c==0){
        if(d==0){
            if(abs(a-b)<=1){
                yes();
                if(b<a){
                    rep(i,1,b)cout<<0<<" "<<1<<" ";
                    cout<<0<<endl;
                }else{
                    rep(i,1,a)cout<<1<<" "<<0<<" ";
                    if(b>a)cout<<1<<endl;
                }
            }else{
                no();
            }
            return 0;
        }else if(b!=0||a!=0){
            no();return 0;
        }else{
            if(d==1){
                yes();
                cout<<3<<endl;
            }else no();
        }
        return 0;
    }
    ll e=a+c-b-d;
    if(abs(e)>1){
        no();return 0;
    }
    n=a+b+c+d;
    if(e>=0){
        rep(i,0,n-1)ans[i]=inf;
        ll pos=0;
        for(ll i=0;i<=a-1;i++){
            ans[pos]=0;pos+=2;
        }
        if(n%2==0)pos=n-2;
        else pos=n-1;
        for(ll i=0;i<=c-1;i++){
            ans[pos]=2;pos-=2;
        }
        pos=1;
        rep(i,1,b){
            ans[pos]=1;pos+=2;
        }
        if(n%2==0)pos=n-1;
        else pos=n-2;
        rep(i,1,d){
            ans[pos]=3;pos-=2;
        }
        if(check()){
            yes();
            rep(i,0,n-1)cout<<ans[i]<<" ";
            return 0;
        }
    }
    if(e<=0){
        rep(i,0,n-1)ans[i]=inf;
        ll pos=0;
        for(ll i=0;i<=b-1;i++){
            ans[pos]=1;pos+=2;
        }
        if(n%2==0)pos=n-2;
        else pos=n-1;
        for(ll i=0;i<=d-1;i++){
            ans[pos]=3;pos-=2;
        }
        pos=1;
        rep(i,1,a){
            ans[pos]=0;pos+=2;
        }
        if(n%2==0)pos=n-1;
        else pos=n-2;
        rep(i,1,c){
            ans[pos]=2;pos-=2;
        }
        if(check()){
            yes();
            rep(i,0,n-1)cout<<ans[i]<<" ";
            return 0;
        }
    }
    no();
    
    return 0;
}