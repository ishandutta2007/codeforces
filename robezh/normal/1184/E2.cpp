#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1100000;
const int maxm = 1000000;
int N,m;
int a[maxm+1],b[maxm+1],W[maxm+1],id[maxm+1];
bool inMST[maxm+1];
int cha[maxn+1];

int find_cha(int x)
{
	if (cha[x]==x) return x;
	else
		return cha[x] = find_cha(cha[x]);
}

void merge(int x,int y)
{
	cha[find_cha(x)] = find_cha(y);
}

bool cmp(int x,int y)
{
	return W[x]<W[y];
}

#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 1000004
#define maxC 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mid ((l + r) >> 1)
#define lc (id << 1)
#define rc (lc + 1)

using namespace std;
int n, u[mn], v[mn], p[mn][24], h[mn], beg[mn], belong[mn];
int num, rig, up[mn], pos[mn], sz[mn], spe[mn], speE[mn];
vector< pair<int, int> > g[mn];
string s;

struct intervalTree
{
    int tree[mn << 2];

    void build(int l, int r, int id)
    {
        if (l == r)
        {
            tree[id] = up[l];
            return;
        }
        build(l, mid, lc);
        build(mid + 1, r, rc);
        tree[id] = max(tree[lc], tree[rc]);
    }

    void update(int l, int r, int id, int x, int v)
    {
        if (l > x || r < x)
            return;
        if (l == r)
        {
            tree[id] = v;
            return;
        }
        update(l, mid, lc, x, v);
        update(mid + 1, r, rc, x, v);
        tree[id] = max(tree[lc], tree[rc]);
    }

    int get(int l, int r, int id, int x, int y)
    {
        if (l > y || r < x)
            return -maxC;
        if (x <= l && r <= y)
            return tree[id];
        int a = get(l, mid, lc, x, y);
        int b = get(mid + 1, r, rc, x, y);
        return max(a, b);
    }
} t;

void dfs(int u)
{
    sz[u] = 1, spe[u] = 0, speE[u] = -maxC;
    FOR(i, 0, int(g[u].size()) - 1)
    {
        int v = g[u][i].F;
        if (v == p[u][0])
            continue;
        p[v][0] = u;
        FOR(j, 1, 23)
            p[v][j] = p[p[v][j - 1]][j - 1];
        h[v] = h[u] + 1;
        dfs(v);
        if (sz[v] > sz[spe[u]])
            spe[u] = v, speE[u] = g[u][i].S;
        sz[u] += sz[v];
    }
}

void hld(int u)
{
    if (!beg[num])
        beg[num] = u;
    belong[u] = num;
    pos[u] = ++ rig;
    if (spe[u])
    {
        hld(spe[u]);
        up[pos[spe[u]]] = speE[u];
        FOR(i, 0, int(g[u].size()) - 1)
        {
            int v = g[u][i].F;
            if (v == p[u][0] || v == spe[u])
                continue;
            beg[++ num] = 0;
            hld(v);
            up[pos[v]] = g[u][i].S;
        }
    }
}

void querry1()
{
    int id, w;
    cin >> id >> w;
    int vert = (h[u[id]] > h[v[id]]? u[id] : v[id]);
    t.update(2, n, 1, pos[vert], w);
}

int goUp(int u, int height)
{
    int dif = h[u] - height;
    FOR(i, 0, 23)
    if ((dif >> i) & 1)
        u = p[u][i];
    return u;
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    b = goUp(b, h[a]);
    if (a == b)
        return a;
    FORD(i, 23, 0)
    if (p[a][i] != p[b][i])
    {
        a = p[a][i];
        b = p[b][i];
    }
    return p[a][0];
}

int get(int a, int b)
{
    int re = - maxC;
    while(belong[a] != belong[b])
    {
        re = max(re, t.get(2, n, 1, pos[beg[belong[a]]], pos[a]));
        a = p[beg[belong[a]]][0];
    }
    return max(re, t.get(2, n, 1, pos[b], pos[a]));
}

void querry2(int a,int b)
{
    int l = lca(a, b);
    int ans = -maxC;
    if (h[a] > h[l])
        ans = max(ans, get(a, goUp(a, h[l] + 1)));
    if (h[b] > h[l])
        ans = max(ans, get(b, goUp(b, h[l] + 1)));
    cout << ans << '\n';
}

void setup()
{
    n=N;
    FOR(i, 1, n)
        g[i].clear();
    
    for (int i=1; i<=m; i++)
    if (inMST[i])
    {
        g[a[i]].pb(mp(b[i], W[i]));
        g[b[i]].pb(mp(a[i], W[i]));
    }
    beg[num = rig = 0] = 0;
}

void xuly()
{
    dfs(1);
    hld(1);
    t.build(2, n, 1);
    for (int i=1; i<=m; i++)
    if (!inMST[i])
		querry2(a[i],b[i]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> N >> m;
	for (int i=1; i<=m; i++)
	{
		cin >> a[i] >> b[i] >> W[i];
		id[i] = i;
	}
	
	sort(id+1,id+1+m,cmp);
	
	for (int i=1; i<=N; i++)
		cha[i] = i;
	
	for (int i=1; i<=m; i++)
		if (find_cha(a[id[i]])!=find_cha(b[id[i]]))
		{
			inMST[id[i]] = true;
			merge(a[id[i]],b[id[i]]);
		}
		else
			inMST[id[i]] = false;
	
	setup();
	xuly();
	

	return 0;
}