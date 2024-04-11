#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll>pii;
#define ff first
#define ss second

ll n,m;
ll par[505050][21];
ll vis[505050];
ll vis2[505050];
vector<pii> v[505050];
ll dep[505050];
ll dep2[505050];

void dfs(ll x,ll d){
    vis[x]=1;
    dep[x]=d;
    for(auto n:v[x]){
        if(vis[n.ss]) continue;
        par[n.ss][0]=x;
        dep2[n.ss]=dep2[x]+n.ff;
        dfs(n.ss,d+1);
    }
}

void f(){
    ll i,j;
    for(j=1;j<21;j++)
        for(i=1;i<=n;i++)
            par[i][j]=par[par[i][j-1]][j-1];
}

ll lca(ll x,ll y){
    if(dep[x]>dep[y]) swap(x,y);
    for(int i=20 ;i>=0;i--){
        if(dep[y]-dep[x]>=(1<<i)) y=par[y][i];
    }

    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(par[x][i]!=par[y][i]){
            x=par[x][i];
            y=par[y][i];
        }
    }
    return par[x][0];
}

int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll i,j,k,l,m,a,b,da,db;
        scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&da,&db);


        for(i=1;i<=n;i++){
            v[i].clear();
            dep[i]=0;
            dep2[i]=0;
            vis[i]=0;

        }
 
       // printf("%lld\n",n);
        for(i=1;i<n;i++){
            ll a,b,c;
            scanf("%lld %lld",&a,&b);
            v[a].emplace_back(1,b);
            v[b].emplace_back(1,a);
        }

        dfs(1,0);
        f();
        ll ddp=0;
        ll mx=0;

        for(i=1;i<=n;i++){
        //    printf("%lld %lld\n",i,dep[i]);
            if(mx<dep[i]){
                ddp=i;
                mx=dep[i];
            }
        }

        if(dep2[a]+dep2[b]-2*dep2[lca(a,b)]<=da){
            printf("Alice\n");
            continue;
        }
        if(db<=2*da){
            printf("Alice\n");
            continue;
        }
        for(i=1;i<=n;i++){
            dep[i]=0;
            dep2[i]=0;
            vis[i]=0;
            
        }

        dfs(ddp,0);


        ll chk=0;
        for(i=1;i<=n;i++){
           // printf("%lld %lld\n",i,dep[i]);
            if(dep[i]>=2*da+1)
                chk=1;
        }
        if(chk)
            printf("Bob\n");
        else printf("Alice\n");
        
    }
}