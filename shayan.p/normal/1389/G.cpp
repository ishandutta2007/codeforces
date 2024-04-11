// And you curse yourself for things you never done
// Shayan.P  2020-07-29

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 3e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

vector<pii> v[maxn], g[maxn];
ll _c[maxn], c[maxn], w[maxn];
bool _ok[maxn], ok[maxn];

int up[maxn], h[maxn];
bool mark[maxn];
int col[maxn], C;
vector<int> vec;

void prep(int u, int par = -1){
    up[u] = h[u];
    mark[u] = 1;
    for(pii p : v[u]){
	if(mark[p.F] == 0){
	    h[p.F] = h[u] + 1;
	    prep(p.F, u);
	    up[u] = min(up[u], up[p.F]);
	}
	else if(p.F != par){
	    up[u] = min(up[u], h[p.F]);
	}
    }    
}
void prep2(int u){
    int SZ = sz(vec);
    mark[u] = 1;
    for(pii p : v[u]){
	if(mark[p.F] == 0){
	    prep2(p.F);
	}
    }
    vec.PB(u);
    if(h[u] == up[u]){
	++C;
	while(sz(vec) > SZ)
	    col[ vec.back() ] = C, vec.pop_back();
    }
}

int sumok[maxn], daddy[maxn];

void prep3(int u, int par = -1){
    sumok[u]+= ok[u];
    for(pii p : g[u])
	if(p.F != par)
	    prep3(p.F, u), sumok[u]+= sumok[p.F];
}
void prep4(int u, int dad, int par = -1){
    if(ok[u])
	dad = u;
    if(u != dad)
	c[dad]+= c[u];
    daddy[u] = dad;
    for(pii p : g[u]){
	if(p.F != par)
	    prep4(p.F, dad, u);
    }
}

ll dpD[maxn], dpU[maxn], ans[maxn];

void dfsDown(int u, int par = -1){
    dpD[u] = c[u];
    for(pii p : g[u]){
	if(p.F != par && ok[p.F]){
	    dfsDown(p.F, u);
	    dpD[u]+= max(ll(0), dpD[p.F] - w[p.S]);
	}
    }
}
void dfsUp(int u, ll num, int par = -1){
    dpU[u] = num;
    for(pii p : g[u]){
	if(p.F != par && ok[p.F]){
	    ll num = dpD[p.F] - w[p.S];
	    if(num < 0){
		dfsUp(p.F, max(ll(0), dpU[u] + dpD[u] - w[p.S]), u);
	    }
	    else{
		dfsUp(p.F, max(ll(0), dpU[u] + dpD[u] - num - w[p.S]), u);
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= k; i++){
	int x;
	cin >> x;
	_ok[x] = 1;
    }
    for(int i = 1; i <= n; i++){
	cin >> _c[i];
    }
    for(int i = 1; i <= m; i++){
	cin >> w[i];
    }
    for(int i = 1; i <= m; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB({b, i});
	v[b].PB({a, i});	    
    }

    memset(mark, 0, sizeof mark);
    prep(1);
    memset(mark, 0, sizeof mark);
    prep2(1);

    for(int u = 1; u <= n; u++){
	c[ col[u] ]+= _c[u];
	ok[ col[u] ]|= _ok[u];	
	for(pii p : v[u]){
	    if(col[u] != col[p.F])
		g[col[u]].PB({col[p.F], p.S});
	}
    }
    
    int root = -1;
    for(int u = 1; u <= C; u++){
	if(ok[u])
	    root = u;
    }
    
    prep3(root);
    for(int u = 1; u <= C; u++){
	ok[u]|= sumok[u] > 0;
    }
    prep4(root, root);

    dfsDown(root);
    dfsUp(root, 0);

    for(int i = 1; i <= C; i++){
	ans[i] = dpD[i] + dpU[i];
    }
    for(int i = 1; i <= n; i++){
	cout << ans[ daddy[ col[i] ] ] << " ";
    }
    return cout << endl, 0;
}