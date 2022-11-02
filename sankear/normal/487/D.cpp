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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int M = 10;
const int N = int(1e5) + 100;

struct tans {

	int l, r;
	pii go[M];

};

int maxv, m, cur;
bool first;
tans rmq[4 * N];
tans tmp[2];
char a[N][M + 5];

inline void merge(tans &a, tans &b, tans &c) {
	c.l = a.l;
	c.r = b.r;
	for (int i = 0; i < m; ++i) {
		if (b.go[i].sc < 0 || b.go[i].sc >= m) {
			c.go[i] = b.go[i];
			continue;
		}
		assert(::a[b.go[i].fs][b.go[i].sc] == '^');
		c.go[i] = a.go[b.go[i].sc];
	}
}

inline void calc(int v) {
	merge(rmq[v * 2], rmq[v * 2 + 1], rmq[v]);
}

inline void init(int pos) {
	rmq[pos + maxv].l = rmq[pos + maxv].r = pos;
	for (int i = 0; i < m; ++i) {
		if (a[pos][i] == '^') {
			rmq[pos + maxv].go[i] = mp(pos, i);
			continue;
		}
		int cur = i;
		while (cur >= 0 && cur < m && a[pos][cur] == a[pos][i]) {
			if (a[pos][cur] == '>') {
				++cur;
			} else {
				--cur;
			}
		}
		if (cur < 0) {
			rmq[pos + maxv].go[i] = mp(pos, -1);
			continue;
		}
		if (cur >= m) {
			rmq[pos + maxv].go[i] = mp(pos, m);
			continue;
		}
		if (a[pos][cur] == '^') {
			rmq[pos + maxv].go[i] = mp(pos, cur);
			continue;
		}
		rmq[pos + maxv].go[i] = mp(-2, -2);
	}
}

inline void recalc(int pos) {
	init(pos);
	pos += maxv;
	while (pos > 1) {
		pos /= 2;
		calc(pos);
	}
}

void get(int v, int gl, int gr, int l, int r) {
	if (gl > r || gr < l) {
		return;
	}
	if (gl >= l && gr <= r) {
		if (first) {
			tmp[cur].l = rmq[v].l;
			tmp[cur].r = rmq[v].r;
			for (int i = 0; i < m; ++i) {
				tmp[cur].go[i] = rmq[v].go[i];
			}
			first = false;
		} else {
			merge(rmq[v], tmp[cur], tmp[1 - cur]);
			cur = 1 - cur;
		}
		return;
	}
	int mid = (gl + gr) / 2;
	get(v * 2 + 1, mid + 1, gr, l, r);
	get(v * 2, gl, mid, l, r);
}

inline pii calc(int x, int y) {
	first = true;
	cur = 0;
	get(1, 0, maxv - 1, 0, x);
	pii ans = tmp[cur].go[y];
	if (ans.fs == 0 && ans.sc >= 0 && ans.sc < m && a[ans.fs][ans.sc] == '^') {
		--ans.fs;
	}
	return ans;
}

inline char get(int c) {
	if (c == 0) {
		return '^';
	}
	if (c == 1) {
		return '<';
	}
	return '>';
}

inline void gen() {
	freopen("D2.in", "w", stdout);
	int n = int(1e5), m = 10, q = int(1e5);
	cout << n << " " << m << " " << q << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m;  ++j) {
			cout << get(rand() % 3);
		}
		cout << endl;
	}
	for (int i = 0; i < int(1e4); ++i) {
		cout << "C " << 1 + rand() % n << " " << 1 + rand() % m << " " << get(rand() % 3) << endl;
	}
	for (int i = 0; i < q - int(1e4); ++i) {
		cout << "A " << 1 + rand() % n << " " << 1 + rand() % m << endl;
	}
	exit(0);
}

int main() {
	//gen();
#ifdef LOCAL42
#define TASK "D"
	freopen(TASK "2.in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
#else

#endif
	int n, q;
	scanf("%d %d %d", &n, &m, &q);
	gets(a[0]);
	for (int i = 0; i < n; ++i) {
		gets(a[i]);
	}
	maxv = 1;
	while (maxv < n) {
		maxv *= 2;
	}
	for (int i = 0; i < n; ++i) {
		init(i);
	}
	for (int i = n; i < maxv; ++i) {
		for (int j = 0; j < m; ++j) {
			rmq[i + maxv].go[j] = mp(-2, -2);
		}
	}
	for (int i = maxv - 1; i > 0; --i) {
		calc(i);
	}
	for (int i = 0; i < q; ++i) {
		char ch;
		scanf(" %c", &ch);
		if (ch == 'C') {
			int x, y;
			scanf("%d %d %c", &x, &y, &ch);
			--x;
			--y;
			a[x][y] = ch;
			recalc(x);
			continue;
		}
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		pii ans = calc(x, y);
		printf("%d %d\n", ans.fs + 1, ans.sc + 1);
	}
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}