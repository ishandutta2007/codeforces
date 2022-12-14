//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define copy kapy_nakonid
#define free dom


const int N = 1e5 + 5 + 150, S = N * 200, ansmod = 1e9 + 7;

const int base[] = {(int) 1e6 + 3, 727};
const int mod[] = {(int) 1e9 + 9, 7 * 17 * (1 << 23) + 1};

int read() { int x; cin >> x; return x; }

int p2[10 + N], pw[10 + N][2], psum[10 + N], code[S][2], cnt[S], xl[S], xr[S], free, root[10 + N], index[N << 4][2], mark[10 + N], par[10 + N];
vector<pair<int, int>> adj[10 + N];

void copy(int x, int y) {
	rep(i, 2)
		code[x][i] = code[y][i];
	xl[x] = xl[y];
	xr[x] = xr[y];
	cnt[x] = cnt[y];
}

void pull(int v, int l, int r) {
	rep(i, 2)
		code[v][i] = (code[l][i] + code[r][i]) % mod[i];
	cnt[v] = cnt[l] + cnt[r];
}

int build(int x, int ind = 1, int b = 0, int e = N - 1) {
	int v = free++;
	index[ind][x] = v;
	if (b + 1 == e) {
		rep(i, 2)
			code[v][i] = pw[b][i] * x;
		cnt[v] = x;
		return v;
	}
	int m = b + e >> 1, l = ind << 1, r = l | 1;
	xl[v] = build(x, l, b, m);
	xr[v] = build(x, r, m, e);
	pull(v, xl[v], xr[v]);
	return v;
}

int set_seg(int i, int j, int id, int x, int ind = 1, int b = 0, int e = N - 1) {
	if (i <= b && e <= j) {
		return index[ind][x];
	}
	int v = free++;
	copy(v, id);
	int m = b + e >> 1, l = ind << 1, r = l | 1;
	if (i < m)
		xl[v] = set_seg(i, j, xl[id], x, l, b, m);
	if (j > m)
		xr[v] = set_seg(i, j, xr[id], x, r, m, e);
	pull(v, xl[v], xr[v]);
	return v;
}

int find(int pos, int v, int b = 0, int e = N - 1) {
	if (pos >= e || cnt[v] == e - b)
		return -1;
	if (b + 1 == e)
		return b;
	int m = b + e >> 1;
	int ansl = find(pos, xl[v], b, m);
	if (ansl == -1)
		return find(pos, xr[v], m, e);
	return ansl;
}

int get(int pos, int v, int b = 0, int e = N - 1) {
	if (b + 1 == e) {
		return cnt[v];
	}
	int m = b + e >> 1;
	if (pos < m)
		return get(pos, xl[v], b, m);
	return get(pos, xr[v], m, e);
}

int add(int pos, int v) {
	int r = find(pos, v);
//	while (get(r, v))
//		r++;
	v = set_seg(pos, r, v, 0);
	v = set_seg(r, r + 1, v, 1);
	return v;
}

int lcps(int x, int y, int b = 0, int e = N - 1) {
	if (code[x][0] == code[y][0] && code[x][1] == code[y][1] && cnt[x] == cnt[y])
		return -1;
	if (b + 1 == e)
		return b;
	int m = b + e >> 1;
	int ansr = lcps(xr[x], xr[y], m, e);
	if (ansr == -1)
		return lcps(xl[x], xl[y], b, m);
	return ansr;
}

bool cmp(int x, int y) {
	int l = lcps(x, y);
	if (~l) {
		assert(get(l, x) != get(l, y));
		return get(l, x) < get(l, y);
	}
	return 1;
}
struct set_cmp {
	bool operator() (int x, int y) {
		return cmp(root[x], root[y]);
	}
};

set<int, set_cmp> st;

void show(int v, int cnt = 0) {
	if (v == -1) {
		cout << cnt << '\n';
		return;
	}
	show(par[v], cnt + 1);
	cout << v + 1 << ' ';
}

int getval(int x) {
	int res = 0;
	rep(i, N - 1)
		res = (res + get(i, x) * p2[i]) % ansmod;
	return res;
}

void relax(int v) {
	mark[v] = 1;
	for (auto e : adj[v]) {
		int u = e.first, w = e.second;
		if (mark[u])
			continue;
		int new_index = add(w, root[v]);
//		cout << v << " -> " << u << endl;
//		cout << getval(root[v]) << ' ' << getval(root[u]) << ' ' << getval(root[v]) + (1 << w) << " == " << getval(new_index) << ' ' << cmp(new_index, root[u]) << ' ' << lcps(new_index, root[u]) << ' ' << code[new_index] << ' ' << code[root[u]] << ' ' << cnt[new_index] << ' ' << cnt[root[u]] << endl; 
		if (cmp(new_index, root[u])) {
			st.erase(u);
			root[u] = new_index;
			par[u] = v;	
			st.insert(u);
		}
	}
}



int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(par, -1, sizeof par);
	int n = read(), m = read();
	rep(i, N - 1) {
		rep(j, 2)
			pw[i][j] = (i != 0? pw[i - 1][j] * 1LL * base[j] % mod[j]: 1);
		p2[i] = (i != 0? p2[i - 1] * 2 % ansmod: 1);
	}
	rep(i, m) {
		int u = read() - 1, v = read() - 1, w = read();
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int source = read() - 1, sink = read() - 1;
	build(0);
	build(1);
	rep(v, n) {
		if (source == v)
			copy(root[v] = free++, index[1][0]);
		else
			copy(root[v] = free++, index[1][1]);
	}
	st.insert(source);
	while ((int) st.size()) {
		int v = *(st.begin());
		st.erase(st.begin());
		if (!mark[v])
			relax(v);
	}
	if (!mark[sink]) {
		cout << -1;
		return 0;
	}
	assert(free < S);
	cout << getval(root[sink]) << '\n';
	show(sink);
}