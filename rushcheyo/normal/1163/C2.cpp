// cf gqcsb

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int n, x[1005], y[1005];

struct line {
	int a, b, c;
	line(int x = 0, int y = 0, int z = 0) {
		int g = gcd(gcd(x, y), z);
		a = x / g, b = y / g, c = z / g;
	}
};
vector<line> vl;
bool operator<(const line &a, const line &b) {
	if (a.a != b.a)
		return a.a < b.a;
	if (a.b != b.b)
		return a.b < b.b;
	if (a.c != b.c)
		return a.c < b.c;
	return false;
}
bool operator==(const line &a, const line &b) {
	return a.a == b.a && a.b == b.b && a.c == b.c;
}
map<line, int> sz;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", x + i, y + i);
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			vl.emplace_back(y[i] - y[j], x[j] - x[i], x[i] * y[j] - x[j] * y[i]);
	sort(vl.begin(), vl.end());
	vl.erase(unique(vl.begin(), vl.end()), vl.end());
	int tot = vl.size();
	for (const line &p : vl)
		++sz[line(p.a, p.b, 0)];
	long long ans = 0;
	for (const auto &p : sz)
		ans += 1LL * p.second * (tot - p.second);
	printf("%lld\n", ans / 2);
	return 0;
}