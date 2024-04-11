#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
 
#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);

ll arr[505050];
vector<pii> v[505050];
ll vis[505050];
ll ans[505050];
ll dis[505050];
ll n,m;

void bfs(ll x){
    queue<ll> q;
    q.push(x);
    vis[x]=3;
    while(q.size()){
        ll x=q.front();
        q.pop();
        for(auto k:v[x]){
            ll typ=k.ss;
            ll loc=k.ff;
           // cout<<x<<' '<<typ<<' '<<loc<<' '<<vis[loc]<<' '<<(vis[loc]&typ)<<'\n';
            if(vis[loc]&typ) continue;
            if(vis[loc]==0){
                vis[loc]+=typ;
            }
            else{
                dis[loc]=dis[x]+1;
                ans[loc]=2-vis[loc];
                vis[loc]=3;
                q.push(loc);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;

    ll i,j,k,l;    
    cin>>n>>m;
    if(n==1){
        cout<<0<<'\n'<<1<<'\n';
        return 0;
    }

    for(i=1;i<=m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        //v[a].pb({b,c});
        v[b].pb({a,c+1});
    }


    bfs(n);


    if(dis[1]==0) cout<<"-1"<<'\n';
    else cout<<dis[1]<<'\n';

    
    for(i=1;i<=n;i++){
        if(vis[i]==3){
            cout<<ans[i];
        }
        else{
            if(vis[i]==0) cout<<1;
            else cout<<2-vis[i];
        }
    }

    
}