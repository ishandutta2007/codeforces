
 #include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_int
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
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////

#define N 300005
ll n;
ll w[N];
struct edge{
    ll to;
    ll c;
};
vector<edge>e[N];

bool used[N];
ll ans=0;
ll dfs(ll par){
    ll ma1=0,ma2=0;
    for(auto x:e[par]){
        ll y=x.to;
        if(used[y])continue;
        used[y]=true;
        ll t=dfs(y)-x.c;
        if(t>ma1){
            ma2=ma1;
            ma1=t;
        }else if(t>ma2){
            ma2=t;
        }
    }
    Max(&ans,ma1+ma2+w[par]);
    
    return w[par]+ma1;
}

int main(){
    cin>>n;
    rep(i,0,n-1)cin>>w[i];
    rep(i,1,n-1){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        edge f;f.to=b;f.c=c;
        e[a].pb(f);
        f.to=a;
        e[b].pb(f);
    }
    //memset(used,false,sizeof(used));
    used[0]=true;
    dfs(0);
    cout<<ans<<endl;
    
    
    return 0;
}