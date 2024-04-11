#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#define MAX_V 200010

int V; 
vector<int> G[MAX_V], rG[MAX_V];
vector<int> vs; 

bool vis[MAX_V];
int cmp[MAX_V]; 

void add_edge(int from, int to)
{
    G[from].pb(to);
    rG[to].pb(from);
}

void dfs(int v)
{
    vis[v] = true;

    for (int to : G[v]) {
	if (!vis[to]) dfs(to);
    }

    vs.push_back(v);
}

void rdfs(int v, int k)
{
    vis[v] = true;
    cmp[v] = k;

    for (int to : rG[v]) {
	if (!vis[to]) rdfs(to, k);
    }
}

int scc()
{
    memset(vis, 0, sizeof(vis));
    vs.clear();

    rep(v, V) if (!vis[v]) dfs(v);
    
    memset(vis, 0, sizeof(vis));

    int k = 0;
    reverse(ALL(vs));

    for (int v : vs) if (!vis[v]) rdfs(v, k++);

    return k;
}

int n;
int p[200010];
vi g[200010];
int cnt;
vi vec;
int ans[200010];

int main() {
    scanf("%d", &n);

    V = n;

    rep(i, n) {
	scanf("%d", &p[i]);
	--p[i];
	ans[i] = p[i];

	if (i != p[i]) {
	    add_edge(p[i], i);
	} 
    }

    set<int> po;

    int sz = scc();

    rep(i, n) {
	if (cmp[i] == cmp[p[i]]) {
	    if (!po.count(cmp[i])) {
		po.insert(cmp[i]);
		vec.pb(i);

	    }
	}
    }

    int idx = -1;

    rep(i, vec.size()) {
	if (vec[i] == p[vec[i]]) idx = i;
    }

    int ret = vec.size();
    if (idx != -1) --ret;

    printf("%d\n", ret);

    if (idx != -1) {
	rep(i, vec.size()) {
	    ans[vec[i]] = vec[idx];
	}
    } else {
	rep(i, vec.size()) {
	    ans[vec[i]] = vec[0];
	}
    }

    rep(i, n) printf("%d%c", ans[i] + 1, i == n - 1 ? '\n' : ' ');
    
    return 0;
}