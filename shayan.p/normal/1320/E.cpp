// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define tm STH_STRANGE

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int h[maxn], sp[20][maxn], st[maxn], C = 0;
vector<int> v[maxn];

void dfs(int u, int par = 0){
    h[u] = h[par] + 1;
    st[u] = C++;
    sp[0][u] = par;
    for(int i = 1; i < 20; i++)
	sp[i][u] = sp[i-1][sp[i-1][u]];	
    for(int y : v[u])
	if(y != par)
	    dfs(y, u);
}
int lca(int a, int b){
    if(h[a] < h[b])
	swap(a, b);
    for(int i = 19; i >= 0; i--)
	if(h[ sp[i][a] ] >= h[b])
	    a = sp[i][a];
    if(a == b)
	return a;
    for(int i = 19; i >= 0; i--)
	if(sp[i][a] != sp[i][b])
	    a = sp[i][a], b = sp[i][b];
    return sp[0][a];
}

int spd[maxn], beg[maxn], imp[maxn];
int col[maxn], tm[maxn], ext[maxn];
bool mark[maxn];

vector<int> verts;
vector<pii> g[maxn];

priority_queue< pair<pii, int> > pq; // -time // -virus // vertice

int mkay(int a, int b){
    return ((a%b) + b)%b;
}
void add(int u){
    mark[u] = 1;
    for(pii p : g[u]){
	if(mark[p.F])
	    continue;
	int t = tm[u] + ((p.S - ext[u] + spd[ col[u] ] - 1) / spd[ col[u] ]);
	if((pii){t, col[u]} < (pii){tm[p.F], col[p.F]})
	    ext[p.F] = mkay(-p.S+ext[u], spd[ col[u] ]), col[p.F] = col[u], tm[p.F] = t, pq.push({ {-tm[p.F],-col[u]}, p.F });
    }
}
void init(){
    while(sz(pq))
	pq.pop();
    for(int u : verts)
	col[u] = -1, tm[u] = inf, mark[u] = 0;
}
void solve(int n){
    init();
    for(int i = 0; i < n; i++){
	col[ beg[i] ] = i;
	tm[ beg[i] ] = 0;
	ext[ beg[i] ] = 0;
	add( beg[i] );
    }
    while(sz(pq)){
	auto p = pq.top();
	pq.pop();
	if(mark[p.S])
	    continue;
	add(p.S);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    
    int q;
    cin >> q;
    while(q--){
	int N, M;
	cin >> N >> M;
	verts.clear();
	for(int i = 0; i < N; i++){
	    cin >> beg[i] >> spd[i];
	    verts.PB(beg[i]);
	}
	for(int i = 0; i < M; i++){
	    cin >> imp[i];
	    verts.PB(imp[i]);
	}
	sort(verts.begin(), verts.end(), [&](int i, int j){ return st[i] < st[j]; } );
	verts.resize( unique(verts.begin(), verts.end()) - verts.begin() );
	for(int i = sz(verts)-1; i > 0; i--)
	    verts.PB(lca(verts[i], verts[i-1]));
	sort(verts.begin(), verts.end(), [&](int i, int j){ return st[i] < st[j]; } );
	verts.resize( unique(verts.begin(), verts.end()) - verts.begin() );
	for(int u : verts)
	    g[u].clear();
	for(int i = 1; i < sz(verts); i++){
	    int A = verts[i], B = lca(verts[i-1], verts[i]);
	    g[A].PB({B, h[A] - h[B]});
	    g[B].PB({A, h[A] - h[B]});
	}
	solve(N);
	for(int i = 0; i < M; i++)
	    cout << col[ imp[i] ] + 1 << " ";
	cout << "\n";
    }
    return 0;
}