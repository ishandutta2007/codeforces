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
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;

const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
const int INF = INT_MAX / 2;

const int UNKO = 300;

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
	int N, Q; cin >> N >> Q;
	vector<int> a(Q), b(Q), A(Q), B(Q);
	rep(k, Q) {
		scanf("%d%d", &a[k], &b[k]);
		a[k]--; b[k]--;
	}
	vector<i_i> ab(Q);
	rep(k, Q) ab[k] = i_i(a[k], b[k]);
	sort(ab.begin(), ab.end());
	ab.erase(unique(ab.begin(), ab.end()), ab.end());
	int L = ab.size();
	vector<int> p(Q);
	rep(k, Q) p[k] = lower_bound(ab.begin(), ab.end(), i_i(a[k], b[k])) - ab.begin();
	for (int l = 0; l < Q; l += UNKO) {
		int r = min(Q, l + UNKO);
		vector<int> V;
		for (int k = l; k < r; k++) V.pb(a[k]), V.pb(b[k]);
		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		int n = V.size();
		for (int k = l; k < r; k++) {
			A[k] = lower_bound(V.begin(), V.end(), a[k]) - V.begin();
			B[k] = lower_bound(V.begin(), V.end(), b[k]) - V.begin();
		}
		vector<bool> used(L), exist(L);
		for (int k = l; k < r; k++) used[p[k]] = true;
		union_find uf(N * 2);
		rep(k, l) {
			exist[p[k]] = !exist[p[k]];
			if (!used[p[k]]) {
				uf.unite(a[k], N + b[k]);
				uf.unite(N + a[k], b[k]);
			}
		}
		bool ok = true;
		rep(u, N) if (uf.same(u, N + u)) ok = false;
		union_find _uf(n * 2);
		rep(i, n) for (int j = i + 1; j < n; j++) {
			int u = V[i], v = V[j];
			if (uf.same(u, v)) _uf.unite(i, j);
			if (uf.same(N + u, v)) _uf.unite(n + i, j);
			if (uf.same(u, N + v)) _uf.unite(i, n + j);
			if (uf.same(N + u, N + v)) _uf.unite(n + i, n + j);
		}
		for (int k0 = l; k0 < r; k0++) {
			exist[p[k0]] = !exist[p[k0]];
			union_find uf = _uf;
			bool wei = ok;
			for (int k = l; k < r; k++) if (exist[p[k]]) {
				uf.unite(A[k], n + B[k]);
				uf.unite(n + A[k], B[k]);
				if (uf.same(A[k], n + A[k])) wei = false;
				if (uf.same(B[k], n + B[k])) wei = false;
			}
			printf("%s\n", wei ? "YES" : "NO");
		}
	}
}