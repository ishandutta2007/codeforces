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
typedef vector<int> vi;
struct edge { int v; ll w; };

const int MOD = 1000000007;
double EPS = 1e-10;
ll INF = INT_MAX;

struct bit {
	vector<int> v;
	bit(int n) : v(n + 1) {}
	int sum(int i) {
		int res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, int x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
};

char _s[100010];

int f(char c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
}

void update(int i, char c, int z, vector<vector<vector<bit> > >& b) {
	int k = f(c);
	for (int t = 1; t <= 10; t++)
		b[k][t][i % t].add(i / t, z);
}

int main() {
	string s; scanf("%s", _s); s = _s;
	int N = s.length();
	vector<vector<vector<bit> > > b(4, vector<vector<bit> >(11, vector<bit>(10, 0)));
	rep(k, 4)
		for (int t = 1; t <= 10; t++)
			rep(i0, 10)
				b[k][t][i0] = bit(N / t + 10);
	rep(i, N) update(i, s[i], 1, b);
	int Q; cin >> Q;
	while (Q--) {
		int q; scanf("%d", &q);
		if (q == 1) {
			int i; scanf("%d", &i); i--;
			char c; scanf("%s", _s); c = _s[0];
			update(i, s[i], -1, b);
			s[i] = c;
			update(i, s[i], 1, b);
		}
		if (q == 2) {
			int l, r; scanf("%d%d", &l, &r); l--;
			string w; scanf("%s", _s); w = _s;
			int t = w.length();
			int ans = 0;
			rep(j, t) {
				int k = f(w[j]), i0 = (l + j) % t;
				ans += b[k][t][i0].sum((r - i0 + t - 1) / t) - b[k][t][i0].sum((l - i0 + t - 1) / t);
			}
			printf("%d\n", ans);
		}
	}
}