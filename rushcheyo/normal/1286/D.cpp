#include <bits/stdc++.h>
using namespace std;

// 1-p[i] 0 <
// p[i]   1 >
// 0:00, 1:01, 2:10, 3:11

const int N = 100005, P = 998244353;
int n, inv100, x[N], v[N], p[N], T[N << 2][2][2];
bool fix0[N], fix1[N], ban10[N];

int power(int a, int x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}

void pushup(int u, int mid) {
	for (int ll = 0; ll < 2; ++ll)
		for (int rr = 0; rr < 2; ++rr) {
			long long tmp = 0;
			for (int lr = 0; lr < 2; ++lr)
				for (int rl = 0; rl < 2; ++rl) {
					if (ban10[mid] && lr == 1 && rl == 0) continue;
					tmp += 1ll * T[u << 1][ll][lr] * T[u << 1 | 1][rl][rr];
				}
			T[u][ll][rr] = tmp % P;
		}
}

void build(int u, int l, int r) {
	if (l == r) {
		T[u][0][0] = 1 - p[l], T[u][1][1] = p[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u, mid);
}
void modify(int u, int l, int r, int pos) {
	if (l == r) {
		T[u][0][0] = fix1[l] ? 0 : 1 - p[l], T[u][1][1] = fix0[l] ? 0 : p[l];
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid) modify(u << 1, l, mid, pos);
	else modify(u << 1 | 1, mid + 1, r, pos);
	pushup(u, mid);
}

int main() {
	inv100 = power(100, P - 2);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", x + i, v + i, p + i), p[i] = 1ll * p[i] * inv100 % P;
	int ans = 0;
	vector<pair<pair<int, int>, pair<int, int>>> g;
	for (int i = 1; i < n; ++i) {
		g.push_back({{x[i + 1] - x[i], v[i] + v[i + 1]}, {i, 2}});
		if (v[i] < v[i + 1]) g.push_back({{x[i + 1] - x[i], v[i + 1] - v[i]}, {i, 0}});
		else if (v[i] > v[i + 1]) g.push_back({{x[i + 1] - x[i], v[i] - v[i + 1]}, {i, 3}});
	}
	sort(g.begin(), g.end(), [](const pair<pair<int, int>, pair<int, int>> &a, const pair<pair<int, int>, pair<int, int>> &b) { return 1ll * a.first.first * b.first.second < 1ll * b.first.first * a.first.second; });
	build(1, 1, n);
	for (int i = 0; i < g.size(); ++i) {
		if (i) {
			if (g[i - 1].second.second == 0) fix1[g[i - 1].second.first + 1] = true, modify(1, 1, n, g[i - 1].second.first + 1);
			else if (g[i - 1].second.second == 3) fix0[g[i - 1].second.first] = true, modify(1, 1, n, g[i - 1].second.first);
			else ban10[g[i - 1].second.first] = true, modify(1, 1, n, g[i - 1].second.first + 1), modify(1, 1, n, g[i - 1].second.first);
		}
		int pos = g[i].second.first;
		bool tmp[4] = {fix0[pos], fix1[pos], fix0[pos + 1], fix1[pos + 1]};
		fix0[pos] |= !(g[i].second.second & 2);
		fix1[pos] |= g[i].second.second & 2;
		fix0[pos + 1] |= !(g[i].second.second & 1);
		fix1[pos + 1] |= g[i].second.second & 1;
		modify(1, 1, n, pos), modify(1, 1, n, pos + 1);
		int res = 0;
		for (int a = 0; a < 2; ++a)
			for (int b = 0; b < 2; ++b)
				res = (res + T[1][a][b]) % P;
		ans = (ans + 1ll * g[i].first.first * power(g[i].first.second, P - 2) % P * res) % P;
		fix0[pos] = tmp[0], fix1[pos] = tmp[1], fix0[pos + 1] = tmp[2], fix1[pos + 1] = tmp[3];
		modify(1, 1, n, pos), modify(1, 1, n, pos + 1);
	}
	printf("%d\n", (ans + P) % P);
}