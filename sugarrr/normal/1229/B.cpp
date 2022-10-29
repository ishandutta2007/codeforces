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
///////////////////////////////////////

#define N 100005
ll gcd(ll a,ll b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}

vector<ll>chi[N];
ll par[N];
ll a[N];
ll ans=0;
vector<l_l>sco[N];
vector<l_l>comp(vector<l_l>a){
    vector<l_l>res;
    sort(a.begin(),a.end());
    ll as=a.size();
    ll pos=0;
    while(pos<=as-1){
        if(pos+1<=as-1&&a[pos].first==a[pos+1].first){
            ll sum=a[pos].second;pos++;
            while(pos+1<=as-1&&a[pos].first==a[pos+1].first){
                sum+=a[pos].second;
                pos++;
            }
            sum+=a[pos].second;
            res.pb(l_l(a[pos].first,sum));
            pos++;
        }else{
            res.pb(a[pos]);
            pos++;
        }
    }
    return res;
}

int dfs(ll t){
    for(auto c:chi[t]){
        vector<l_l>res;
        res.pb(l_l(a[c],1));
        for(auto p:sco[t]){
            l_l ne;ne.second=p.second;
            ne.first=gcd(p.first,a[c]);
            Add(ans,mod(ne.first)*ne.second);
            res.pb(ne);
        }
        //sco[c]=res;
        sco[c]=comp(res);
        dfs(c);
    }
    return 0;
}

int main(){fastio
    ll n;cin>>n;
    rep(i,0,n-1)cin>>a[i];
    vector<ll>v[n];
    rep(i,1,n-1){
        ll b,c;cin>>b>>c;b--;c--;
        v[b].pb(c);
        v[c].pb(b);
    }
    memset(par,-1,sizeof(par));
    
    par[0]=-2;
    queue<ll>q;q.push(0);
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(par[x]!=-1)continue;
            chi[t].pb(x);
            par[x]=t;
            q.push(x);
        }
    }
    
    /*rep(i,0,n-1){
        cout<<i<<" ";
        for(auto x:chi[i])cout<<x<<" ";
        cout<<endl;
    }*/
    
    rep(i,0,n-1)ans+=a[i];
    sco[0].pb(l_l(a[0],1));
    dfs(0);
    /*rep(i,0,n-1){
        cout<<i<<":"<<endl;
        for(auto x:sco[i]){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }*/
    
    cout<<ans<<endl;
    
    
    return 0;
}