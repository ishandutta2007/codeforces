#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005, B = 316;
int n, nq, l[N], r[N], k[N], tot = 1, ch[N][26], fail[N], pos[N], in[N], out[N], seq[N], dfs_clock, tag[N], val[N];
bool ed[N];
vector<int> t[N];
ll ans[N], sub[N], sum[N];
vector<int> qry[N];
string s[N];

void dfs(int u) {
	seq[in[u] = ++dfs_clock] = u;
	for (int v : t[u]) dfs(v);
	out[u] = dfs_clock;
}

void update(int l, int r) {
	for (int i = l; i <= min(r, ((l - 1) / B + 1) * B); ++i)
		++val[i];
	if ((l - 1) / B != (r - 1) / B) {
		for (int j = (l - 1) / B + 2; j <= (r - 1) / B; ++j)
			++tag[j];
		for (int j = (r - 1) / B * B + 1; j <= r; ++j)
			++val[j];
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> nq;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		int u = 1;
		for (char c : s[i]) {
			if (!ch[u][c - 'a']) ch[u][c - 'a'] = ++tot;
			u = ch[u][c - 'a'];
		}
		ed[u] = true;
		pos[i] = u;
	}
	queue<int> q;
	for (int i = 0; i < 26; ++i)
		if (ch[1][i]) q.push(ch[1][i]), fail[ch[1][i]] = 1;
		else ch[1][i] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++i)
			if (ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
			else ch[u][i] = ch[fail[u]][i];
	}
	for (int i = 2; i <= tot; ++i)
		t[fail[i]].push_back(i);
	dfs(1);
	for (int i = 1; i <= nq; ++i) {
		cin >> l[i] >> r[i] >> k[i];
		if (s[k[i]].size() > B)
			qry[k[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i)
		if (s[i].size() > B) {
			fill(sub + 1, sub + 1 + tot, 0);
			int u = 1;
			for (char c : s[i]) {
				u = ch[u][c - 'a'];
				++sub[u];
			}
			for (int j = tot; j > 1; --j)
				sub[fail[seq[j]]] += sub[seq[j]];
			for (int j = 1; j <= n; ++j)
				sum[j] = sum[j - 1] + sub[pos[j]];
			for (int q : qry[i])
				ans[q] = sum[r[q]] - sum[l[q] - 1];
			qry[i].clear();
		}
	for (int i = 1; i <= nq; ++i)
		if (s[k[i]].size() <= B) qry[r[i]].push_back(i), qry[l[i] - 1].push_back(-i);
	for (int i = 1; i <= n; ++i) {
		update(in[pos[i]], out[pos[i]]);
		for (int q : qry[i]) {
			int u = 1;
			for (char c : s[k[abs(q)]]) {
				u = ch[u][c - 'a'];
				ans[abs(q)] += (q > 0 ? 1 : -1) * (tag[(in[u] - 1) / B + 1] + val[in[u]]);
			}
		}
	}
	for (int i = 1; i <= nq; ++i)
		cout << ans[i] << '\n';
	return 0;
}