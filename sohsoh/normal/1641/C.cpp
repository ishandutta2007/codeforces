#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const pair<int, pll> IDK = {-1, {-1, -1}};

int n, q;
pair<int, pll> sg[MAXN];
vector<pair<int, pll>> vec[MAXN];

void add(int ql, int qr, int qind, int l = 1, int r = n, int v = 1) {
	if (l == r) {
		vec[v].push_back({qr, {ql, qind}});
	} else {
		int mid = (l + r) >> 1;
		if (ql <= mid) add(ql, qr, qind, l, mid, v << 1);
		else add(ql, qr, qind, mid + 1, r, v << 1 | 1);
	}
}

void remove(int ind, int l = 1, int r = n, int v = 1) {
	if (l == r) {
		vec[v].pop_back();	
		sg[v] = (vec[v].empty() ? IDK : vec[v].back());
	} else {
		int mid = (l + r) >> 1;
		if (ind <= mid) remove(ind, l, mid, v << 1);
		else remove(ind, mid + 1, r, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) {
		sort(all(vec[v]));
		sg[v] = (vec[v].empty() ? IDK : vec[v].back());
	} else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

pair<int, pll> query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l) return IDK;
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return max(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

bool B[MAXN], vis[MAXN];
int ps[MAXN], f[MAXN], m;
pll seg[MAXN];
set<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<pll> Q;
	vector<string> ans;

	cin >> n >> q;
	for (int i = 1; i <= n; i++) B[i] = true, st.insert(i);

	for (int i = 1; i <= q; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			int l, r, x;
			cin >> l >> r >> x;
			if (x == 1) {
				seg[++m] = {l, r};
				Q.push_back({1, m});
			} else {
				while (true) {
					auto it = st.lower_bound(l);
					if (it == st.end() || *it > r) break;
					
					int ind = *it;
					Q.push_back({2, ind});
					B[ind] = false;
					st.erase(it);
				}
			}
		} else {
			int ind;
			cin >> ind;
			Q.push_back({3, ind});
		}
	}

	for (int i = 1; i <= n; i++)
		ps[i] = ps[i - 1] + int(B[i]);

	for (int i = 1; i <= m; i++) {
		int l = seg[i].X, r = seg[i].Y;
		if (ps[r] - ps[l - 1] == 1)
			add(l, r, i);
	}

	build();
	reverse(all(Q));
	for (auto qu : Q) {
		int t = qu.X, ind = qu.Y;
		if (t == 1) vis[ind] = true;
		else if (t == 2) {
			while (true) {
				auto e = query(1, ind);
				if (e.X >= ind) remove(e.Y.X);
				else break;
			}

			B[ind] = true;
		} else {
			if (!B[ind]) {
				ans.push_back("NO");
				continue;
			}

			bool flag = false;
			while (true) {
				auto e = query(1, ind);
				if (e.X >= ind) {
					if (vis[e.Y.Y]) remove(e.Y.X);
					else {
						flag = true;
						break;
					}
				} else break;
			}

			if (flag) ans.push_back("YES");
			else ans.push_back("N/A");
		}
	}

	reverse(all(ans));
	for (string s : ans)
		cout << s << endl;
	return 0;
}