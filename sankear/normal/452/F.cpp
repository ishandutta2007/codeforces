#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL42
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif
#define next _next
#define prev _prev
#define hash _hash
#define rank _rank
#define link _link

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> tc;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(3e5) + 100;
const int M1 = 42424243;
const int M2 = int(1e9) + 7;
const int P1 = 10007;
const int P2 = 4243;

struct hash {

	int a, b;

	hash() {}

	hash(int a, int b) {
		this->a = a;
		this->b = b;
	}

};

hash operator + (const hash &a, const hash &b) {
	hash c(a.a + b.a, a.b + b.b);
	if (c.a >= M1) {
		c.a -= M1;
	}
	if (c.b >= M2) {
		c.b -= M2;
	}
	return c;
}

hash operator * (const hash &a, const hash &b) {
	return hash((1LL * a.a * b.a) % M1, (1LL * a.b * b.b) % M2);
}

bool operator == (const hash &a, const hash &b) {
	return a.a == b.a && a.b == b.b;
}

struct rmq {

	int maxv;
	hash rmq[4 * N];

	inline void init(int n) {
		maxv = 1;
		while (maxv < n) {
			maxv *= 2;
		}
	}

	inline void add(int p, hash h) {
		p += maxv;
		rmq[p] = h;
		while (p > 1) {
			p /= 2;
			rmq[p] = rmq[p * 2] + rmq[p * 2 + 1];
		}
	}

	inline hash get(int l, int r) {
		l += maxv;
		r += maxv;
		hash res(0, 0);
		while (l <= r) {
			if (l % 2 != 0) {
				res = res + rmq[l];
			}
			l = (l + 1) / 2;
			if (r % 2 == 0) {
				res = res + rmq[r];
			}
			r = (r - 1) / 2;
		}
		return res;
	}

};

rmq R, RR;
hash p[N];

int main() {
	int n;
	scanf("%d", &n);
	R.init(n);
	RR.init(n);
	p[0] = hash(1, 1);
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] * hash(P1, P2);
	}
	for (int i = 0; i < n; ++i) {
		int cur;
		scanf("%d", &cur);
		--cur;
		R.add(cur, p[cur]);
		RR.add(cur, p[n - cur - 1]);
		if (cur > 0 && cur + 1 < n) {
			int can = min(cur, n - cur - 1);
			hash l = R.get(cur - can, cur - 1) * p[n - (cur - can)];
			hash r = RR.get(cur + 1, cur + can) * p[n - (n - (cur + can) - 1)];
			if (l == r) {
				continue;
			}
			cerr << i << endl;
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}