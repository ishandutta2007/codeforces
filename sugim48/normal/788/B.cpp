#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
#include <cassert>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
ll INF = LLONG_MAX / 3;

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	int N, M; cin >> N >> M;
	vector<int> a(M), b(M);
	rep(i, M) scanf("%d%d", &a[i], &b[i]), a[i]--, b[i]--;
	union_find uf(N);
	rep(i, M) uf.unite(a[i], b[i]);
	rep(i, M) if (!uf.same(a[0], a[i])) {
		cout << 0 << endl;
		return 0;
	}
	int loop = 0;
	rep(i, M) if (a[i] == b[i]) loop++;
	ll ans = (ll)loop * (loop - 1) / 2 + (ll)loop * (M - loop);
	vector<int> d(N);
	rep(i, M) if (a[i] != b[i]) d[a[i]]++, d[b[i]]++;
	rep(u, N) ans += (ll)d[u] * (d[u] - 1) / 2;
	cout << ans << endl;
}