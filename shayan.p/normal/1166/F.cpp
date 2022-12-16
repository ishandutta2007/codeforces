// High above the clouds there is a rainbow...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int n,c,par[maxn];
vector<int>vec[maxn];
map<int,int>lst[maxn];
set<int>adj[maxn];

void merge(int a,int b){
    a=par[a],b=par[b];
    if(a==b) return;
    if(sz(vec[a])<sz(vec[b])) swap(a,b);
    if(sz(adj[a])<sz(adj[b])) swap(adj[a],adj[b]);
    for(int u:vec[b]) vec[a].PB(u),par[u]=a;
    vec[b].clear();
    for(int u:adj[b]) adj[a].insert(u);
    adj[b].clear();
}

void add(int x,int y,int z){
    if(lst[x].count(z)) merge(lst[x][z],y);
    if(lst[y].count(z)) merge(lst[y][z],x);
    lst[x][z]=y,lst[y][z]=x;
    adj[par[x]].insert(y);
    adj[par[y]].insert(x);
}
bool ask(int a,int b){
    return par[a]==par[b] || adj[par[a]].count(b);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m,q;cin>>n>>m>>c>>q;
    
    for(int i=1;i<=n;i++){
	par[i]=i;
	vec[i].PB(i);
    }
    while(m--){
	int x,y,z;cin>>x>>y>>z;
	add(x,y,z);
    }
    while(q--){
	char ch;cin>>ch;
	if(ch=='+'){
	    int x,y,z;cin>>x>>y>>z;
	    add(x,y,z);
	}
	else{
	    int x,y;cin>>x>>y;
	    cout<<(ask(x,y) ? "Yes\n" : "No\n");
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.