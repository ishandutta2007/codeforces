#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
	if (!x && !y)
		return 1;
	if (!x && y)
		return y;
	if (x && !y)
		return x;
	int t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}

struct point {
	int x;
	int y;

	void get() {
		scanf("%d%d", &x, &y);
	}
};

struct vec {
	int x;
	int y;

	vec() {
		x = 0;
		y = 0;
	}

	vec(point p1, point p2) {
		x = p2.x - p1.x;
		y = p2.y - p1.y;
		int g = gcd(abs(x), abs(y));
		x /= g;
		y /= g;
	}

	int dir() const {
		return x == 0 ? y > 0 : x > 0;
	}

	bool operator<(vec o) const {
		return x == o.x ? y < o.y : x < o.x;
	}
};

map<vec, int> m;
int c[100005][2];

void solve() {
	int n;
	scanf("%d", &n);
	memset(c, 0, sizeof c);
	m.clear();
	int cnt = 1;
	point p1, p2;
	vec v;
	for (int i = 0; i < n; ++i) {
		p1.get();
		p2.get();
		vec v(p1, p2);
		vec v1 = v;
		if (!v.dir()) {
			v1.x *= -1;
			v1.y *= -1;
		}
		if (m[v1] == 0)
			m[v1] = cnt++;
		++c[m[v1]][v.dir()];
	}
	long long res = 0;
	for (int i = 1; i < cnt; ++i) {
		res += 1LL * c[i][0] * c[i][1];
	}
	printf("%lld\n", res);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}