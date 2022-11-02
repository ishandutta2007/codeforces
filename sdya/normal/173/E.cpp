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

void Build( int n, int *x, int *y, int *value )
{
  N = n;
  if (!N)
    return;
  P.resize(n + 2);
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

void Change( int i, int newValue )
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

int Get( int x1, int y1, int x2, int y2 )
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

const int maxN = 210000;

int n, k, m;
int x[maxN], y[maxN], value[maxN];
int cnt[maxN];
int u[maxN], v[maxN];

bool comp(int p, int q) {
	return max(x[u[p]], x[v[p]]) > max(x[u[q]], x[v[q]]);
}

bool comp2(int p, int q) {
	return x[p] > x[q];
}

int order[maxN];
int add_order[maxN];

map < int, int > M;
set < int > S;

int t[4 * maxN];

void update(int i, int l, int r, int k, int delta) { 
	if (l == r) {
		t[i] = max(t[i], delta);
		return ;
	}
	if (k > (l + r) / 2)
		update(2 * i + 1, (l + r) / 2 + 1, r, k, delta); else
		update(2 * i, l, (l + r) / 2, k, delta);
	t[i] = max(t[2 * i], t[2 * i + 1]);
}

int get(int i, int cl, int cr, int l, int r) {
	if (l > r) return -1;
	if (cl == l && cr == r) {
		return t[i];
	}

	if (l > (cl + cr) / 2)
		return get(2 * i + 1, (cl + cr) / 2 + 1, cr, l, r);
	if (r <= (cl + cr) / 2)
		return get(2 * i, cl, (cl + cr) / 2, l, r);
	int A = get(2 * i, cl, (cl + cr) / 2, l, (cl + cr) / 2);
	int B = get(2 * i + 1, (cl + cr) / 2 + 1, cr, (cl + cr) / 2 + 1, r);
	return max(A, B);
}

int res[maxN];

int ny[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &x[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &y[i]), value[i] = 1;

	Build(n, x, y, value);
	for (int i = 0; i < n; ++i)
		cnt[i] = Get(0, y[i] - k, x[i], y[i] + k);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
		scanf("%d%d", &u[i], &v[i]), --u[i], --v[i], order[i] = i;
	sort(order, order + m, comp);

	memset(t, -1, sizeof(t));

	for (int i = 0; i < n; ++i) {
		S.insert(y[i] - k);
	}

	int vR = 0;
	for (set < int > :: iterator it = S.begin(); it != S.end(); ++it) {
		++vR;
		M[* it] = vR;
		ny[vR] = * it;
	}

	for (int i = 0; i < n; ++i)
		add_order[i] = i;
	sort(add_order, add_order + n, comp2);

	int cur_index = 0;
	for (int i = 0; i < m; ++i) {
		int g = u[order[i]], h = v[order[i]];

		int p = max(x[g], x[h]);
		while (cur_index < n) {
			if (x[add_order[cur_index]] >= p) {
				update(1, 1, vR, M[y[add_order[cur_index]] - k], cnt[add_order[cur_index]]);
			} else break;
			++cur_index;
		}

		if (y[g] > y[h]) swap(g, h);

		int left_bound = y[h] - 2 * k, right_bound = y[g];
		set < int > :: iterator it = S.lower_bound(left_bound);
		if (it == S.end()) {
			res[order[i]] = -1;
			continue;
		}

		if (S.empty()) {
			res[order[i]] = -1;
			continue;
		}

		int v1 = M[* it], v2 = -1;
		it = S.upper_bound(right_bound);
		if (it == S.end()) {
			v2 = M[* S.rbegin()];
		} else {
			v2 = M[* it];
		}

		if (ny[v2] > right_bound) --v2;
		res[order[i]] = get(1, 1, vR, v1, v2);
	}

	for (int i = 0; i < m; ++i)
		printf("%d\n", res[i]);

	return 0;
}