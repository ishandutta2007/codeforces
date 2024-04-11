#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int maxN = 110000;
int t[4 * maxN], m;

int get(int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res = max(res, t[i]);
	}
	return res;
}

void update(int k, int delta) {
	for (int i = k; i <= m; i |= (i + 1)) {
		t[i] = max(t[i], delta);
	}
}

int calculate(vector < pair < int, int > > borders) {
	pair < int, int > start = borders[0];
	sort(borders.rbegin(), borders.rend());

	for (int i = 0; i < borders.size(); ++i) {
		int current = get(borders[i].second - 1);
		update(borders[i].second, current + 1);
		if (borders[i] == start) {
			return current;
		}
	}
}

int a, b, c, d, n;

struct rational {
	long long x, y;
	rational(long long x, long long y) : x(x), y(y) {
	}
	rational() : x(0), y(1) {
	}

	bool operator < (const rational &other) const {
		return x * other.y < other.x * y;
	}
};

vector < pair < int, int > > compress(vector < rational > a, vector < rational > b) {
	set < rational > S;
	for (int i = 0; i < a.size(); ++i) {
		S.insert(a[i]);
		S.insert(b[i]);
	}
	map < rational, int > M;
	m = 0;
	for (set < rational > :: iterator it = S.begin(); it != S.end(); ++it) {
		M[* it] = ++m;
	}
	vector < pair < int, int > > borders;
	for (int i = 0; i < a.size(); ++i) {
		borders.push_back(make_pair(M[a[i]], M[b[i]]));
	}
	return borders;
}

int main() {
	scanf("%d", &n);
	scanf("%d/%d%d/%d", &a, &b, &c, &d);

	vector < rational > u, v;
	for (int i = 0; i <= n; ++i) {
		long long x, y;
		if (i == 0) {
			x = y = 0;
		} else {
			cin >> x >> y;
		}
		u.push_back(rational(1000000LL * a + y * b - x * a, a + b));
		v.push_back(rational(1000000LL * c + y * d - x * c, c + d));
	}

	printf("%d\n", calculate(compress(u, v)));

	return 0;
}