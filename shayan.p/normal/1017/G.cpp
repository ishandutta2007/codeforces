// only miss the sun when it starts to snow

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

const int maxn=1e5+10, SQ=300;

vector<int> v[maxn], vec;
vector<pii> g[maxn];

int t[maxn],ver[maxn];
bool in[maxn], cln[maxn];

int sp[20][maxn], h[maxn], st[maxn], nw;

bool state[maxn];
int smu[maxn], tdo[maxn];

void prep(int u,int par=0){
    st[u]= nw++;
    h[u]=h[par]+1;
    sp[0][u]=par;
    for(int i=1;i<20;i++)
	sp[i][u]= sp[i-1][sp[i-1][u]];
    for(int y:v[u])
	prep(y,u);
}
int lca(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[sp[i][a]]>=h[b]) a=sp[i][a];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
	if(sp[i][a]!=sp[i][b]) a=sp[i][a], b=sp[i][b];
    }
    return sp[0][a];
}

void prep2(int u){
    smu[u]= state[ sp[0][u] ] + smu[ sp[0][u] ];
    for(int y:v[u])
	prep2(y);
}

void add(int u){
    if(state[u]==0){
	state[u]=1;
	return;
    }
    tdo[u]++;
    for(pii &p:g[u]){
	if(p.S==0) add(p.F);
	else p.S--;
    }
}
void del(int u){
    cln[u]=1;
    state[u]=0;
    tdo[u]=0;
    for(pii &p:g[u]){
	p.S= h[p.F]-h[u]-1;
	del(p.F);
    }
}

void goc(int u){
    if(in[u]) return;
    state[u]=0;
    for(int y:v[u])
	goc(y);
}
void go(int u,int cnt){
    if(in[u] || cnt==0) return;
    if(state[u]==0) cnt--, state[u]=1;
    for(int y:v[u])
	go(y,cnt);
}
void rest(int u){
    if(cln[u]){
	for(int y:v[u])
	    goc(y);
    }
    for(int y:v[u]){
	go(y,tdo[u]);
    }
    for(pii p:g[u]){
	rest(p.F);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,q; cin>>n>>q;

    for(int i=2;i<=n;i++){
	int x; cin>>x;
	v[x].PB(i);
    }
    prep(1);

    for(int i=0;i<q;i++){
	cin>>t[i]>>ver[i];
    }
    for(int l=0;l<q;l+=SQ){
	int r=min(q,l+SQ);
	
	memset(tdo,0,sizeof tdo);
	memset(in,0,sizeof in);
	memset(cln,0,sizeof cln);	
	vec.clear();
	
	prep2(1);
	
	for(int i=l;i<r;i++){
	    vec.PB(ver[i]);
	}
	sort(vec.begin(), vec.end(), [](int a,int b){ return st[a]<st[b]; } );
	for(int i=sz(vec)-1;i>0;i--){
	    vec.PB( lca( vec[i], vec[i-1] ) );
	}
	sort(vec.begin(), vec.end(), [](int a,int b){ return st[a]<st[b]; } );

	vec.resize( unique(vec.begin(), vec.end()) - vec.begin() );

	for(int u:vec){
	    in[u]=1;
	    g[u].clear();
	}
	for(int i=1;i<sz(vec);i++){
	    int A=lca( vec[i], vec[i-1] );
	    int B=vec[i];
	    g[A].PB({B, h[B]-h[A]-1-(smu[B]-state[A]-smu[A])});
	}

	for(int i=l;i<r;i++){
	    if(t[i]==1){
		add(ver[i]);
	    }
	    if(t[i]==2){
		del(ver[i]);
	    }
	    if(t[i]==3){
		cout<<(state[ver[i]] ? "black\n" : "white\n");
	    }
	}
	rest(vec[0]);
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")