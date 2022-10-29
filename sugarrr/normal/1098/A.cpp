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



int main(){
    ll n;cin>>n;
    ll p[n];vector<ll>chi[n];
    rep(i,1,n-1){
        cin>>p[i];p[i]--;
        chi[p[i]].pb(i);
    }
    ll a[n],s[n];
    rep(i,0,n-1)cin>>s[i];
    queue<l_l>q;
    a[0]=s[0];q.push(l_l(0,1));
    while(!q.empty()){
        l_l t=q.front();q.pop();
        ll par=t.first,num=t.second;
        for(auto x:chi[par])q.push(l_l(x,num+1));
        if(num==1)continue;
        if(num%2==0){
            ll m=inf;
            for(auto x:chi[par]){
                m=min(m,s[x]);
            }
            if(m==inf){
                a[par]=0;
            }else{
                s[par]=m;
                a[par]=s[par]-s[p[par]];
            }
            if(a[par]<0){cout<<-1<<endl;return 0;}
        }else{
            a[par]=s[par]-s[p[par]];
            if(a[par]<0){cout<<-1;return 0;}
        }
    }
   /*rep(i,0,n-1){
        cout<<a[i]<<" ";
    }cout<<endl;*/
    ll ans=0;rep(i,0,n-1)ans+=a[i];cout<<ans<<endl;
    
    return 0;
}