//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 2e6 + 6;

int read() { int x; scanf("%d", &x); return x; }
int a[N], par[N], pick[N], eq[N], trash[N], res[N], mark[N], dp[N];
pair<int, int> sr[N], s[N];
vector<int> in[N];


int find(int v) {
	return v == par[v]? v: par[v] = find(par[v]);
}
void unite(int u, int v) {
	u = find(u);
	v = find(v);
	par[u] = v;
}

map<int, int> ans;


int32_t main() {
//	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read(), k = n * m, p = 0;
	rep(i, n)
		rep(j, m) {
			a[i * m + j] = read();
			par[i * m + j] = i * m + j;
		}
	rep(i, n) {
		rep(j, m) {
			s[j] = {a[i * m + j], j};
		}
		sort(s, s + m);
		for (int j = 1; j < m; ++j) {
			if (s[j].first == s[j - 1].first) {
				unite(s[j].second + i * m, s[j - 1].second + i * m);
			}
		}
	}
	rep(j, m) {
		rep(i, n) {
			s[i] = {a[i * m + j], i};
		}
		sort(s, s + n);
		for (int i = 1; i < n; ++i) {
			if (s[i].first == s[i - 1].first) {
				unite(s[i].second * m + j, s[i - 1].second * m + j);
			}
		}
	}
	rep(i, n) {
		rep(j, m) {
			s[j] = {a[i * m + j], j};
			sr[i * m + j] = {a[i * m + j], find(i * m + j)};
		}
		sort(s, s + m);
		for (int j = 1; j < m; ++j) {
			if (s[j].first != s[j - 1].first) {
				in[find(s[j].second + i * m)].push_back(find(s[j - 1].second + i * m));
//				unite(s[j].second + i * m, s[j - 1].second + i * m);
			}
		}
	}
	rep(j, m) {
		rep(i, n) {
			s[i] = {a[i * m + j], i};
		}
		sort(s, s + n);
		for (int i = 1; i < n; ++i) {
			if (s[i].first != s[i - 1].first) {
//				cout << s[i].second << ' ' << s[i - 1].second << endl;
				in[find(s[i].second * m + j)].push_back(find(s[i - 1].second * m + j));
//				unite(s[i].second * m + j, s[i - 1].second * m + j);
			}
		}
	}
//	return 0;
	sort(sr, sr + k);
	k = unique(sr, sr + k) - sr;
	rep(z, k) {
		int i = sr[z].second;
		for (int x : in[i]) {
//			cout << i << ' ' << x << endl;
			dp[i] = max(dp[i], dp[x] + 1);
		}
	}
//	return 0;
	rep(i, n) {
		rep(j, m)
			printf("%d ", dp[find(i * m + j)] + 1);
		printf("\n");
	}
}