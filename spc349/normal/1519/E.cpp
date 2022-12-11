#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int N;
vector <pii> ans;
map <pll, int> ID;
vector <pii> from[400010];
int vis[400010], ins[400010];

long long gcd(long long x, long long y) {
	return !y ? x : gcd(y, x % y);
}

int GetId(int a, int b, int c, int d) {
	long long x = 1ll * a * d, y = 1ll * b * c;
	long long tmp = gcd(x, y);
	x /= tmp, y /= tmp;
	if (ID.count(mp(x, y))) return ID[mp(x, y)];
	return ID[mp(x, y)] = N++;
}

int dfs(int x) {
	vis[x] = 1, ins[x] = 1;
	int cur = -1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, id = from[x][i].se;
		if (vis[v]) {
			if (!ins[v]) {
				if (cur != -1) ans.push_back(mp(id, cur)), cur = -1;
				else cur = id;
			}
			continue;
		}
		int tmp = dfs(v);
		if (tmp != -1) ans.push_back(mp(id, tmp));
		else {
			if (cur != -1) ans.push_back(mp(id, cur)), cur = -1;
			else cur = id;
		}
	}
	ins[x] = 0;
	return cur;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		int x = GetId(a + b, b, c, d), y = GetId(a, b, c + d, d);
		from[x].push_back(mp(y, i));
		from[y].push_back(mp(x, i));
	}
	for (int i = 0; i < N; i++) {
		if (!vis[i]) dfs(i);
	}
	printf("%d\n", (int)ans.size());
	for (auto it : ans) printf("%d %d\n", it.fi + 1, it.se + 1);
	return 0;
}