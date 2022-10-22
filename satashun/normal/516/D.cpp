#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<int, ll> pil;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define MX 100010

int n, q;
int ret;
ll lim;
vector<pil> g[MX];
ll d[MX], len[MX];
multiset<ll> st[MX];
priority_queue<ll> que[MX];

void dfs1(int v, int p)
{
    for (auto e : g[v]) {
	if (e.fi != p) {
	    dfs1(e.fi, v);
	    len[v] = max(len[v], len[e.fi] + e.se);
	}
    }
    d[v] = len[v];
}

void dfs2(int v, int p, ll maxi)
{    
    d[v] = max(d[v], maxi);

    for (auto e : g[v]) {
	if (e.fi != p) {
	    st[v].insert(len[e.fi] + e.se);
	}
    }

    for (auto e : g[v]) {
	if (e.fi != p) {
	    ll nl = len[e.fi] + e.se;
	    st[v].erase(st[v].find(nl));
	    ll nm = maxi;

	    if (st[v].size()) 
		nm = max(nm, *st[v].rbegin());
	    
	    dfs2(e.fi, v, nm != -1 ? nm + e.se : -1);
	    st[v].insert(nl);
	}
    }    
}

void dfs(int v, int p)
{
    while(que[v].size()) que[v].pop();
    que[v].push(d[v]);

    for (pii e : g[v]) {
	if (e.fi != p) {
	    dfs(e.fi, v);

	    while (que[e.fi].size() && que[e.fi].top() > d[v] + lim) que[e.fi].pop();

	    if (que[v].size() < que[e.fi].size()) {
		que[v].swap(que[e.fi]);
	    }

	    for (; que[e.fi].size(); que[e.fi].pop()) que[v].push(que[e.fi].top());
	}
    }
    
    ret = max(ret, (int)que[v].size());
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    rep(i, n-1) {
	int a, b, c;
	cin >> a >> b >> c;
	--a; --b;
	g[a].eb(b, c);
	g[b].eb(a, c);
    }

    dfs1(0, -1);
    dfs2(0, -1, g[0].size() == 1 ? 0 : -1);

    int root = 0;

    rep(i, n) if (d[root] > d[i]) root = i;

    cin >> q;

    while (q--) {
	cin >> lim;
	ret = 0;
	dfs(root, -1);
	cout << ret << endl;
    }

    return 0;
}