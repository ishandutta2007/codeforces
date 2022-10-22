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

const ll MAXN = 4e6 + 10;

vector<int> v;
vector<pll> st[MAXN];
int n, m, par[MAXN];
pll lz[MAXN], sg[MAXN];

inline void push(int v) {
	if (lz[v].X) {
		sg[v] = max(sg[v], lz[v]);
		if ((v << 1 | 1) < MAXN) {
			lz[v << 1] = max(lz[v << 1], lz[v]);
			lz[v << 1 | 1] = max(lz[v << 1 | 1], lz[v]);
		}

		lz[v] = {0, 0};
	}	
}

void update(int ql, int qr, pll val, int l = 1, int r = 2 * m, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] = max(lz[v], val);
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, val, l, mid, v << 1);
	update(ql, qr, val, mid + 1, r, v << 1 | 1);
	sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
}

pll query(int ql, int qr, int l = 1, int r = 2 * m, int v = 1) {
	push(v);
	if (ql > r || qr < l) return {0, 0};
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return max(query(ql, qr, l, mid, v << 1), 
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

inline int pnt(int a) {
	return lower_bound(all(v), a) - v.begin() + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int ind, l, r;
		cin >> ind >> l >> r;
		st[ind].push_back({l, r});
		v.push_back(l);
		v.push_back(r);
	} 
	
	sort(all(v));
	for (int i = 1; i <= n; i++) {
		pll ans = {0, 0};
		for (pll e : st[i]) 
			ans = max(ans, query(pnt(e.X), pnt(e.Y)));
		par[i] = ans.Y;
		ans.X++;
		for (pll e : st[i])
			update(pnt(e.X), pnt(e.Y), {ans.X, i});
	}
	
	set<int> st;
	for (int i = 1; i <= n; i++) st.insert(i);
	int ind = query(1, 2 * m).Y;

	while (ind) {
		st.erase(ind);
		ind = par[ind];
	}

	cout << st.size() << endl;
	for (int e : st) cout << e << sep;
	cout << endl;
	return 0;
}