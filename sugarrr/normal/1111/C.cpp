
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
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-8;
////////////////////////////////////////

struct node{
    ll many;
    ll cost;
    ll k;
    bool operator<(const node x)const{
        return k<x.k;
    }
};

int main(){
    ll n,k,a,b;cin>>n>>k>>a>>b;
    ll N=(1ll<<n);
    ll c[k];
    rep(i,0,k-1){
        cin>>c[i];
        c[i]--;
    }
    sort(c,c+k);
    vector<node>v[n+1];
    vector<l_l>ini;
    ll pos=0;
    while(pos<=k-1){
        ll where=c[pos];
        ll cou=1;
        while(pos<=k-2&&c[pos+1]==c[pos]){
            cou++;
            pos++;
        }
        ini.pb(l_l(where+N-1,cou));
        pos++;
    }
    for(auto x:ini){
        node z;
        z.many=x.second;
        z.cost=b*z.many*1;
        z.k=x.first;
        v[n].pb(z);
    }
    sort(v[n].begin(),v[n].end());
    for(ll i=n-1;i>=0;i--){
        ll vs=v[i+1].size();
        if(vs==0)continue;
        rep(j,0,vs-1){
            node z;
            if(j<=vs-2&&v[i+1][j].k+1==v[i+1][j+1].k&&v[i+1][j].k%2==1){
                z.k=(v[i+1][j].k-1)/2;
                z.many=v[i+1][j].many+v[i+1][j+1].many;
                z.cost=z.many*b*(1<<(n-i));
                Min(z.cost,v[i+1][j].cost+v[i+1][j+1].cost);
                j++;
            }else{
                z.k=(v[i+1][j].k-1)/2;
                z.many=v[i+1][j].many;
                z.cost=z.many*b*(1<<(n-i));
                Min(z.cost,v[i+1][j].cost+a);
            }
            v[i].pb(z);
        }
        sort(v[i].begin(),v[i].end());
    }
    /*rep(i,0,n){
        for(auto x:v[i]){
            cout<<x.cost<<" "<<x.many<<" "<<x.k<<endl;
        }
        cout<<endl;
    }*/
    cout<<v[0][0].cost<<endl;
    
    
    return 0;
}