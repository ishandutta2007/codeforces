#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N=200200;
vector<int> g[N];
vector<int> ch[N];
vector<int> ord;
int tin[N], tout[N];
int par[N];
int tot = 0;

void d(int u, int p = -1) {
	ord.push_back(u);
	tin[u] = tot++;
	for(int v : g[u]) 
		if (v != p)  {
			ch[u].push_back(v);
			par[v] = u;
			d(v, u);
		}
	tout[u] = tot;
}

pair<int, int> t[4 * N];
int lazy[4 * N];

const int oo = 0x3f3f3f3f;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {0, tl};
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = {0, tl};
    }
}

void push(int v) {
    t[v*2].first += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1].first += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v].first += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

pair<int,int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {-oo, -1};
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k; 
	cin >> n >> k;
	for(int j = 0; j < n - 1; ++j) {
		 int a, b;
		 cin >> a >> b;
		 --a, --b;
		 g[a].push_back(b);
		 g[b].push_back(a);
	}
	build(1, 0, n - 1);
	d(0);
	int cl = 0;
	for(int i = 0; i < n; ++i) 
		cl += ch[i].size() == 0;
	if (cl <= k) {
		nagai ans = -1e18;
		for(int i = cl; i <= k; ++i) {
			ans = max(ans, (nagai)(n - i) * i);
		}
		cout << ans << '\n';
		return 0;
	}
	for(int i = 0; i < n;++i) {
		update(1, 0, n - 1, tin[i], tout[i] - 1, 1);
	}
	for(int i = 0; i < n;++i) {
		if (ch[i].size()) 
			update(1, 0, n - 1, tin[i], tin[i], -oo);
	}
	vector<bool> used(n);
	int res = 0;
	for(int i = 0; i < k; ++i) {
		auto kek = query(1, 0, n - 1, 0, n - 1);
		assert(kek.first >= 0);
		kek.second = ord[kek.second];
		assert(kek.second >= 0 && ch[kek.second].size() == 0);
		int x = kek.second;
		update(1, 0, n - 1, tin[kek.second], tout[kek.second] - 1, -oo);
		while (!used[x]) {
			used[x] = true;
			++res;
			update(1, 0, n - 1, tin[x], tout[x] - 1, -1);
			x = par[x];
		}
	}
	cerr << res << '\n';
	nagai ans = 1e18;
	int mxb = n - res;
	for(int i = 0; i <= mxb; ++i) {
		ans = min(ans, 1LL * (n - i - k) * (k - i));
	}
	cout << ans << '\n';
}