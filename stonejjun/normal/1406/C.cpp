#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back

ll arr[1010101];
vector<ll> adj[101010];
ll sz[1010101];

int getSz(int here,int dad){
    sz[here]=1;
    for(auto there:adj[here]){
        if(there==dad)continue;
        sz[here]+=getSz(there,here);
    }
    return sz[here];
}
 
int get_centroid(int here,int dad,int cap){
    //cap <---- (tree size)/2
    for(auto there:adj[here]){
        if(there==dad)continue;
        if(sz[there]>cap) return get_centroid(there,here,cap);
    }
    return here;
}


bool sf(ll a,ll b){
	return sz[a]>sz[b];
}

 
int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll i,j,k,l,m,a,b,da,db,n;
        scanf("%lld",&n);
 
 
        for(i=1;i<=n;i++){
            adj[i].clear();
            sz[i]=0;
        }
 
        for(i=1;i<n;i++){
            ll a,b,c;
            scanf("%lld %lld",&a,&b);
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        

        ll root=1;
        getSz(root,-1);
        ll center=get_centroid(1,-1,sz[root]/2);
        for(i=1;i<=n;i++){
            sz[i]=0;
        }
        getSz(center,-1);

        for(i=1;i<=n;i++)
        	sort(adj[i].begin(), adj[i].end(),sf);

        ll x=center;
        while(adj[x].size()!=1){
        	//printf("%lld %lld\n",center,x);
        	if(x==center)x=adj[x][0];
        	else x=adj[x][1];
        }
        printf("%lld %lld\n%lld %lld\n",x,adj[x][0],x,center);
    }
}