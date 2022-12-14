#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
int n, m, s[10][10], to[N], id1[N], id2[N], ans1[N], ans2[N];
vector<string> g1, g2;
vector<vector<int>> p1, p2;

int id(char c) { return c == 'L' ? 1 : c == 'R' ? 2 : c == 'T' ? 3 : 4; }
int encode(int x, int y) { return x <= 2 ? (x - 1) * n + y : 2 * n + (x - 3) * m + y; }
pair<int, int> decode(int c) {
	if (c <= 2 * n) return make_pair((c - 1) / n + 1, (c - 1) % n + 1);
	else return make_pair(2 + (c - 2 * n - 1) / m + 1, (c - 2 * n - 1) % m + 1);
}

void add(int x, int y) { to[x] = y, to[y] = x; }

int getmin(int *s, int n) {
	int i = 0, j = 1, k = 0;
	while (i < n && j < n && k < n) {
		int t = s[(i + k) % n] - s[(j + k) % n];
		if (!t) k++;
		else {
			if (t > 0) i += k + 1;
			else j += k + 1;
			if (i == j) j++;
			k = 0;
		}
	}
	return min(i, j);
}

void get(vector<vector<int>> &p, vector<string> &g) {
	static bool vis[N];
	static int a[N], b[N], ra[N], rb[N];
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n + m << 1; i++)
		if (!vis[i]) {
			int j = i, k, l = 0;
			do {
				vis[j] = true;
				a[l] = decode(j).first, b[l] = j, l++;
				k = to[j], vis[k] = true;
				pair<int, int> tmp = decode(k);
				a[l] = tmp.first, b[l] = k, l++;
				tmp.first += tmp.first & 1 ? 1 : -1;
				j = encode(tmp.first, tmp.second);
			} while (j != i);
			for (int j = 0; j < l; j++)
				ra[j] = a[l - j - 1], rb[j] = b[l - j - 1];
			int st1 = getmin(a, l), st2 = getmin(ra, l);
			string s1, s2;
			for (int j = 0; j < l; j++) s1.push_back(a[(st1 + j) % l] + 'a');
			for (int j = 0; j < l; j++) s2.push_back(ra[(st2 + j) % l] + 'a');
			if (s1 < s2) {
				p.push_back(vector<int>());
				g.push_back(s1);
				for (int j = 0; j < l; j++) p.back().push_back(b[(st1 + j) % l]);
			} else {
				p.push_back(vector<int>());
				g.push_back(s2);
				for (int j = 0; j < l; j++) p.back().push_back(rb[(st2 + j) % l]);
			}
		}
}

bool solve() {
	if (s[1][2] && s[3][4]) return false;
	if (s[1][3] != s[2][4]) return false;
	if (s[1][4] != s[2][3]) return false;
	get(p1, g1);
	for (int i = 1; i <= s[1][3]; i++)
		add(encode(1, i), encode(3, i));
	for (int i = 1; i <= s[2][3]; i++)
		add(encode(2, i), encode(3, m - i + 1));
	for (int i = 1; i <= s[1][4]; i++)
		add(encode(1, n - i + 1), encode(4, i));
	for (int i = 1; i <= s[2][4]; i++)
		add(encode(2, n - i + 1), encode(4, m - i + 1));
	for (int i = 1; i <= s[1][2]; i++)
		add(encode(1, s[1][3] + i), encode(2, s[2][3] + i));
	for (int i = 1; i <= s[3][4]; i++)
		add(encode(3, s[1][3] + i), encode(4, s[1][4] + i));
	get(p2, g2);
	if (p1.size() != p2.size()) return false;
	int k = p1.size();
	for (int i = 0; i < k; i++) id1[i] = id2[i] = i;
	sort(id1, id1 + k, [](int p, int q) { return g1[p] < g1[q]; });
	sort(id2, id2 + k, [](int p, int q) { return g2[p] < g2[q]; });
	for (int i = 0; i < k; i++) {
		if (g1[id1[i]] != g2[id2[i]]) return false;
		int sz = g1[id1[i]].size();
		for (int j = 0; j < sz; j++) {
			int w = decode(p2[id2[i]][j]).first,
				t1 = decode(p1[id1[i]][j]).second,
				t2 = decode(p2[id2[i]][j]).second;
			if (w == 1) ans1[t2] = t1;
			if (w == 3) ans2[t2] = t1;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	char c1, c2;
	for (int i = 1, a, b; i <= n + m; i++) {
		scanf(" %c %c%d%d", &c1, &c2, &a, &b);
		int i1 = id(c1), i2 = id(c2);
		add(encode(i1, a), encode(i2, b));
		if (i1 > i2) swap(i1, i2);
		s[i1][i2]++;
	}
	if (!solve()) puts("No solution");
	else {
		for (int i = 1; i <= n; i++) printf("%d%c", ans1[i], " \n"[i == n]);
		for (int i = 1; i <= m; i++) printf("%d%c", ans2[i], " \n"[i == m]);
	}
}