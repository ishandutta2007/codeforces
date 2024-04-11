//In the name of God

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

const int N = 3e6 + 555, M = 1e4 + 4;

int ql[M], qr[M], cnt[M], m, q, curcnt[M], par[N], ans[N];
pair<int, int> pos[N];
vector<int> g[M];
char s[N];

int read() { int x; cin >> x; return x; }

int find(int v) {
	return v == par[v]? v: par[v] = find(par[v]);
}

void unite(int u, int v) {
	ans[u] = ans[v];
//	u = find(u);
//	v = find(v);
//	par[u] = v;
}

vector<pair<pair<int, int>, int>> solve(bool ok) {
	vector<pair<pair<int, int>, int>> st;
	int n = (int) strlen(s);
	st.push_back({{0, n}, 0});
	for (int t = 0; t < q; ++t) {
		memset(curcnt, 0, sizeof curcnt);
		int i = qr[t], j = qr[t] + qr[t] - ql[t], sz = cnt[t + 26];
		vector<pair<pair<int, int>, int>> tmp = st;
		st.clear();
		vector<int> get;
		int count = 0;
		for (auto it : tmp) {
			int b = it.first.first, e = it.first.second, id = it.second;
			if (ok) {
				for (int k = max(b, ql[t]); k < min(e, qr[t]); ++k) if (k - b + curcnt[id] < cnt[id] && count <= 2 * sz) {
					int v = k - b + curcnt[id];
//					if (s[5] == s[6] && s[6] == s[7] && s[7] == s[8] && s[5] == 'A' && v >= g[id].size()) {
//						cout << g[id].size() << ' ' << v << endl;
//						exit(0);
//					}
					get.push_back(g[id][v]);
					count++;
				} else break;
			}
			curcnt[id] += e - b;
			if (i >= e || i < b) {
				if (i < b)
					b += j - i, e += j - i;
				st.push_back({{b, e}, id});
			} else {
				st.push_back({{b, i}, id});
				st.push_back({{i, j}, t + 26});
				st.push_back({{j, j + (e - b) - (i - b)}, id});
			}
		}
		while ((int) st.size()) {
			if (st.back().first.first >= m) {
				st.pop_back();
				continue;
			}
			break;
		}
		if (ok) {
			int cur = 1;
//			cout << "hi\n";
//			for (int k = 0; k < get.size(); ++k)
//				cout << get[k] << endl;
			for (int k = 0; k < (int) g[t + 26].size(); ++k) {
				if (cur >= qr[t] - ql[t]) {
					cur = 0;
				}
				unite(g[t + 26][k], get[cur]);
//				cout << g[t + 26][k] << endl;
				cur += 2;
			}
		}
	}
	return st;
}

int main() {
//	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	for (int i = 0; i < N; ++i)
//		par[i] = i;
	scanf("%s", s);
	s[strlen(s)] = 'A';
	m = read();
	q = read();
	for (int i = 0; i < q; ++i)
		ql[i] = read() - 1, qr[i] = read();
	auto st = solve(0);
	sort(st.begin(), st.end());
	for (auto it : st) {
		int b = it.first.first, e = it.first.second, id = it.second;
		for (int i = b; i < min(e, m); ++i) {
			pos[i] = {id, cnt[id]};
			if (id < 26)
				ans[i] = s[cnt[id]] - 'A';
			g[id].push_back(i);
			cnt[id]++;
//			cout << i << ' ' << id << endl;
		}
	}
	solve(1);
	for (int i = 0; i < m; ++i)
		printf("%c", char(ans[i] + 'A'));
	
	
	
	
}

/*
ACGTACGT
10
1
1 2
*/