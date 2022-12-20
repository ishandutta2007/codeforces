// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;


ll XXX;

ll n,m;

vector<ll>v[maxn],g[maxn];

ll compon[maxn],block[maxn],bcke[maxn],h[maxn],CNT[maxn];
bool vis[maxn],cut[maxn],good[maxn];

ll CM,BL;
map<ll,vector<ll> >ed[maxn];
map<ll,ll>how[maxn];

pair<ll,bool> sparse[23][maxn];
ll HH[maxn];

inline void add(ll u,ll id){
    g[u].PB(id+n+1);
    g[id+n+1].PB(u);
}

void dfs1(ll u){// filling bcke and h and compon ans CNT
    vis[u]=1;
    compon[u]=CM;
    bcke[u]=h[u];
    for(ll y:v[u]){
	if(!vis[y]){
	    CNT[u]++;
	    h[y]=h[u]+1;
	    dfs1(y);
	    bcke[u]=min(bcke[u],bcke[y]);
	}
	else{
	    bcke[u]=min(bcke[u],h[y]);
	}
    }
}

void dfs2(ll u,ll bl,ll root){
    vis[u]=1;
    block[u]=bl;
    
    if(u==root && CNT[u]==1){
	dfs2(v[u][0],bl,root);
	return;
    }
    
    for(ll y:v[u]){
	if(!vis[y]){
	    if(bcke[y]>=h[u]){
		cut[u]=1;
		add(u,BL+1);
		dfs2(y,++BL,root);
	    }
	    else{
		dfs2(y,bl,root);
	    }
	}
	else if(h[y]<h[u]){
	    ed[bl][u].PB(y);
	    ed[bl][y].PB(u);
	}
    }
    if(cut[u])
	add(u,bl);
}

void dfs3(ll u,ll id){
    ll b=how[id][u];
    for(ll y:ed[id][u]){
	ll x=how[id][y];
	if(x==0){
	    how[id][y]=-b;
	    dfs3(y,id);
	}
	else if(x==b){
	    good[n+1+id]=1;
	}
    }
}

void dfs4(ll u,ll par=0){
    vis[u]=1;
    sparse[0][u]=MP(par,good[u]);
    for(ll y:g[u]){
	if(!vis[y]){
	    HH[y]=HH[u]+1;
	    dfs4(y,u);
	}
    }
}

bool ask(ll a,ll b){
    bool ans=0;
    if(HH[a]<HH[b])swap(a,b);
    FORD(i,20,0){
	if(HH[sparse[i][a].F]>=HH[b]){
	    ans|=sparse[i][a].S;
	    a=sparse[i][a].F;
	}
    }
    FORD(i,20,0){
	if(sparse[i][a]!=sparse[i][b]){
	    ans|=sparse[i][a].S;
	    ans|=sparse[i][b].S;
	    a=sparse[i][a].F;
	    b=sparse[i][b].F;
	}
    }
    ans|=sparse[0][a].S;
    ans|=sparse[0][b].S;
    if(a!=b)
	ans|=sparse[1][a].S;
    return ans;
}

int main(){
    cin>>n>>m;
    REP(i,m){
	ll a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    FOR(i,1,n){
	if(!vis[i]){
	    dfs1(i);
	    CM++;
	}
    }
    memset(vis,0,sizeof vis);
    FOR(i,1,n){
	if(!vis[i]){
	    dfs2(i,BL,i);
	    BL++;
	}
    }
    REP(i,BL){
	ll u=ed[i].begin()->F;
	how[i][u]=1;
	dfs3(u,i);
    }

    memset(vis,0,sizeof vis);
    HH[0]=-1;
    FOR(i,1,maxn-1){
	if(!vis[i]){
	    dfs4(i);
	}
    }
    FOR(i,1,20){
	REP(j,maxn){
	    sparse[i][j].F=sparse[i-1][sparse[i-1][j].F].F;
	    sparse[i][j].S=sparse[i-1][j].S|sparse[i-1][sparse[i-1][j].F].S;
	}
    }

    ll q;cin>>q;
    while(q--){
       	ll a,b;cin>>a>>b;
	ll A=((cut[a])?(a):(block[a]+n+1));
	ll B=((cut[b])?(b):(block[b]+n+1));
	cout<<( (a!=b && compon[a]==compon[b] && (((h[a]+h[b])%2) || ask(A,B) ) )?"Yes\n":"No\n");
    }
}