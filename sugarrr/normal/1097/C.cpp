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
ll inf=(ll)1E12;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////

struct bracket{
    string s;
    ll size;
    bool left=true;
    bool right=true;
    ll lr;
};

int main(){
    ll n;cin>>n;
    bracket a[n];
    rep(i,0,n-1)cin>>a[i].s;
    rep(i,0,n-1){
        a[i].size=a[i].s.size();
        ll c=0;
        rep(j,0,a[i].size-1){
            if(a[i].s[j]=='('){
                c++;
            }else{
                c--;
            }
            if(c<0){
                a[i].left=false;
            }
        }
        a[i].lr=c;
        c=0;
        for(ll j=a[i].size-1;j>=0;j--){
            if(a[i].s[j]=='('){
                c++;
            }else{
                c--;
            }
            if(c>0){
                a[i].right=false;
            }
        }
    }
    vector<ll>l,r;
    ll ans=0;
    ll zerocou=0;
    rep(i,0,n-1){
        if(a[i].left&&a[i].right)zerocou++;
        else if(a[i].left){
            l.pb(a[i].lr);
        }else if(a[i].right){
            r.pb(a[i].lr);
        }
    }
    ans=zerocou/2;
    zerocou-=ans*2;
    
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    ll x=upper_bound(l.begin(),l.end(),0)-lower_bound(l.begin(),l.end(),0);
    ll y=upper_bound(r.begin(),r.end(),0)-lower_bound(r.begin(),r.end(),0);
    if((x+y)%2==1&&zerocou%2==1){
        ans++;
    }
    reverse(l.begin(),l.end());
    ll lpos=0,rpos=0;
    ll ls=l.size(),rs=r.size();
    while(lpos<=ls-1&&rpos<=rs-1){
        ll summ=l[lpos]+r[rpos];
        if(summ==0){
            ans++;
            lpos++;
            rpos++;
        }else if(summ>0){
            lpos++;
        }else{
            rpos++;
        }
    }
    cout<<ans<<endl;
    //for(auto x:l)cout<<x<<" ";cout<<endl;
    //for(auto x:r)cout<<x<<" ";cout<<endl;
    
    
    return 0;
}