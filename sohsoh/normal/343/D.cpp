// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 5e5 + 10;

int sg[MAXN << 2],  sg2[MAXN << 2], lz[MAXN << 2], tin[MAXN], tout[MAXN], n, T;
vector<int> adj[MAXN];

void dfs(int v, int p) {
	tin[v] = ++T;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	tout[v] = T;
}

inline void Push(int v) {
	sg2[v] = max(sg2[v], lz[v]);
	if ((v << 1 | 1) < (MAXN << 2)) {	
		lz[v << 1] = max(lz[v << 1], lz[v]);
		lz[v << 1 | 1] = max(lz[v << 1 | 1], lz[v]);
	}
}

void Update1(int ind, int val, int L = 1, int R = T, int v = 1) {
	if (L == R) {
		sg[v] = max(sg[v], val);
		return;
	}

	int mid = (L + R) >> 1;
	if (ind <= mid) Update1(ind, val, L, mid, v << 1);
	else Update1(ind, val, mid + 1, R, v << 1 | 1);
	sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
}

int Query1(int QL, int QR, int L = 1, int R = T, int v = 1) {
	if (QR < QL) return -1;
	if (QL == L && QR == R) return sg[v];

	int mid = (L + R) >> 1;
	return max(Query1(QL, min(QR, mid), L, mid, v << 1),
		Query1(max(QL, mid + 1), QR, mid + 1, R, v << 1 | 1));
}

void Update2(int QL, int QR, int val, int L = 1, int R = T, int v = 1) {
	Push(v);
	if (QR < QL) return;
	if (QL == L && QR == R) {
		lz[v] = max(lz[v], val);
		Push(v);
		return;
	}

	int mid = (L + R) >> 1;
	Update2(QL, min(QR, mid), val, L, mid, v << 1);
	Update2(max(QL, mid + 1), QR, val, mid + 1, R, v << 1 | 1);
	sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
}

int Query2(int ind, int L = 1, int R = T, int v = 1) {
	Push(v);
	if (L == R) return sg2[v];

	int mid = (L + R) >> 1;
	if (ind <= mid) return Query2(ind, L, mid, v << 1);
	else return Query2(ind, mid + 1, R, v << 1 | 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	dfs(1, 0);

	int q;
	cin >> q;
	for (int t = 1; t <= q; t++) {
		int c, v;
		cin >> c >> v;
		
		if (c == 1) Update2(tin[v], tout[v], t);
		else if (c == 2) Update1(tin[v], t);
		else {
			int mx1 = Query1(tin[v], tout[v]),
			    mx2 = Query2(tin[v]);
			cout << (mx1 >= mx2 ? 0 : 1) << endl;
		}
	}
	return 0;
}