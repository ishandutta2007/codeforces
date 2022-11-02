#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define BS_L(a, x, less) (lower_bound(all(a), x, less) - (a).begin())
#define BS_U(a, x, less) (upper_bound(all(a), x, less) - (a).begin())

typedef vector <int> vi;
typedef vector <vi> vvi;

struct Point
{
	int x, y, value;
	Point() { }
	Point( int _x, int _y, int _value ) : x(_x), y(_y), value(_value) { }
};

int N;
vector <Point> P;
vi Order;
vvi T, Sum;

inline bool xylessi( int a, int b ) { return mp(P[a].x, a) < mp(P[b].x, b); }
inline bool yxlessi( int a, int b ) { return mp(P[a].y, a) < mp(P[b].y, b); }
inline bool xyless( int a, int b ) { return P[a].x < P[b].x; }
inline bool yxless( int a, int b ) { return P[a].y < P[b].y; }

void Build( int n, int *x, int *y, int *value ) // NlogN
{
	N = n;
	if (!N)
		return;
	P.resize(n + 2); // two extra points - for Get() function
	Order.resize(n);
	forn(i, n)
		P[i] = Point(x[i], y[i], value[i]), Order[i] = i;
	sort(all(Order), xylessi);

	T.resize(2 * N);
	Sum.resize(2 * N);
	forn(i, N)
		T[N + i] = vi(1, Order[i]);
	for (int i = N - 1; i >= 1; i--)
	{
		T[i].resize(sz(T[2 * i]) + sz(T[2 * i + 1]));
		merge(all(T[2 * i]), all(T[2 * i + 1]), T[i].begin(), yxlessi);
	}
	for (int i = 1; i < 2 * N; i++)
	{
		int m = sz(T[i]);
		vi &s = Sum[i] = vi(m * 2, 0);
		forn(j, m)
			s[j + m] = P[T[i][j]].value;
		for (int j = m - 1; j >= 1; j--)
			s[j] = s[2 * j] + s[2 * j + 1];
	}
}

void Change( int i, int newValue ) // log^2 N
{  
	assert(0 <= i && i < N);
	int z = BS_L(Order, i, xylessi);
	for (z += N; z > 0; z /= 2)
	{
		int j = BS_L(T[z], i, yxlessi);
		vi &s = Sum[z];
		s[j += sz(T[z])] = newValue;
		for (j /= 2; j > 0; j /= 2)
			s[j] = s[2 * j] + s[2 * j + 1];
	}
}

int InnerGet( int i )
{
	int l = BS_L(T[i], N, yxless);
	int r = BS_U(T[i], N + 1, yxless) - 1;
	int sum = 0;
	vi &s = Sum[i];
	for (l += sz(T[i]), r += sz(T[i]); l <= r; l /= 2, r /= 2)
	{                                                                    
		if (l % 2 == 1) sum += s[l++];
		if (r % 2 == 0) sum += s[r--];
	}
	return sum;
}

int Get( int x1, int y1, int x2, int y2 ) // log^2 N, sum on [x1..x2] x [y1..y2]
{
	if (!N || x1 > x2 || y1 > y2)
		return 0;

	P[N] = Point(x1, y1, 0);
	P[N + 1] = Point(x2, y2, 0);

	int zl = BS_L(Order, N, xyless);
	int zr = BS_U(Order, N + 1, xyless) - 1;
	int sum = 0;
	for (zl += N, zr += N; zl <= zr; zl /= 2, zr /= 2)
	{
		if (zl % 2 == 1) sum += InnerGet(zl++);
		if (zr % 2 == 0) sum += InnerGet(zr--);
	}
	return sum;
}

const int maxN = 110000;
int n, m;
int x[maxN], r[maxN], f[maxN], value[maxN];
int order[maxN];

bool comp(int u, int v) {
	return r[u] < r[v];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &x[i], &r[i], &f[i]);
		value[i] = 1;
		order[i] = i;
	}

	sort(order, order + n, comp);

	Build(n, x, f, value);
	long long res = 0;
	for (int t = 0; t < n; ++t) {
		int i = order[t];

		res += Get(x[i] - r[i], f[i] - m, x[i] + r[i], f[i] + m);
		Change(i, 0);
	}

	cout << res - n << endl;

	return 0;
}