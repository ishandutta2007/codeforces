#include <bits/stdc++.h>

using namespace std;

int qry(int x, int y, int z) {
	printf("? %d %d %d\n", x, y, z);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int cnt[300005];

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int h;
	scanf("%d", &h);
	int n = (1 << h) - 1;
//	mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
//	uniform_int_distribution<int> dist(1, n);
	srand(time(nullptr));
	for (int i = 0; i < 422; ++i) {
		int x = 0, y = 0, z = 0;
//		while (x == y || y == z || z == x) x = dist(rnd), y = dist(rnd), z = dist(rnd);
		while (x == y || y == z || z == x) x = rand() % n + 1, y = rand() % n + 1, z = rand() % n + 1;
		++cnt[qry(x, y, z)];
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; ++i) v.emplace_back(cnt[i], i);
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	int s = v[0].second, t = v[1].second;
	for (int i = 1; i <= n; ++i) {
		if (i == s || i == t) continue;
		int ans = qry(s, t, i);
		if (ans != s && ans != t) {
			printf("! %d\n", ans);
			fflush(stdout);
		}
	}
	return 0;
}