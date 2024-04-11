#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

struct Rational {
	long long p, q;
	Rational() : p(0), q(1) {}
	Rational(long long p_, long long q_) {
		p = p_;
		q = q_;
		if (q < 0) {
			p = -p;
			q = -q;
		}
		long long d = gcd(abs(p), abs(q));
		p /= d;
		q /= d;
	}
	bool operator < (const Rational &other) const {
		return make_pair(p, q) < make_pair(other.p, other.q);
	}
};

struct Point {
	Rational x, y;
	Point() {}
	Point(Rational x, Rational y) : x(x), y(y) {}
};

struct Line {
	long long A, B, C;
	void read() {
		scanf("%I64d%I64d%I64d", &A, &B, &C);
	}

	bool contains(const Point &p) const {
		return A * p.x.p * p.y.q + B * p.y.p * p.x.q + C * p.x.q * p.y.q == 0;
	}
};

bool intersect(const Line &l1, const Line &l2, Point &p) {
	long long D = l1.A * l2.B - l1.B * l2.A;
	if (D == 0) {
		return false;
	}

	long long u = l1.C * l2.B - l1.B * l2.C;
	long long v = l1.A * l2.C - l1.C * l2.A;

	p.x = Rational(-u, D);
	p.y = Rational(-v, D);
	return true;
}

Line l[maxN];
int n, m;

inline int getPos(int n) {
	int res = rand() * rand() + rand();
	res %= n;
	if (res < 0) {
		res += n;
	}
	return res;
}

bool solve(vector < int > ids, int cnt, vector < pair < int, int > > &res) {
	if (ids.size() == 0) {
		return true;
	}
	if (cnt == 0) {
		return false;
	}
	if (ids.size() == 1) {
		res.push_back(make_pair(ids[0] + 1, -1));
		return true;
	}

	double q = (double)(cnt * cnt - 1) / (double)(cnt * cnt);
	double p = 1.0;

	int needed = (ids.size() + cnt - 1) / cnt;
	int maxAttempts = 3;
	int attempts = 0;
	while (p > 1e-3 && attempts < maxAttempts) {
		p *= q;

		int u = -1, v = -1;
		while (true) {
			u = getPos(ids.size());
			v = getPos(ids.size());
			if (u == v) {
				continue;
			} else {
				break;
			}
		}

		Point s;
		if (!intersect(l[ids[u]], l[ids[v]], s)) {
			continue;
		}

		vector < int > notthere;
		int in = 0, out = 0;
		for (int i = 0; i < ids.size(); ++i) {
			if (l[ids[i]].contains(s)) {
				++in;
			} else {
				++out;
				notthere.push_back(ids[i]);
			}

			if (in + ids.size() - (i + 1) < needed) {
				break;
			}
		}
		if (in < needed) {
			continue;
		}

		vector < pair < int, int > > cur;
		if (solve(notthere, cnt - 1, cur)) {
			res = cur;
			res.push_back(make_pair(ids[u] + 1, ids[v] + 1));
			return true;
		}
		++attempts;
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		l[i].read();
	}

	vector < int > ids;
	for (int i = 0; i < n; ++i) {
		ids.push_back(i);
	}

	vector < pair < int, int > > res;
	if (solve(ids, m, res)) {
		printf("YES\n");
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); ++i) {
			printf("%d %d\n", res[i].first, res[i].second);
		}
	} else {
		printf("NO\n");
	}

	return 0;
}