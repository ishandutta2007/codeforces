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
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef pair<int, ll> i_ll;
struct edge { int u, v; ll w; };

double INF = DBL_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct bit {
	vector<ll> v;
	bit(int n) : v(n + 1) {}
	ll sum(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, ll x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
	ll get(int i) {
		return sum(i + 1) - sum(i);
	}
};

int main() {
	int N, Q; cin >> N >> Q;
	bit bt(N);
	for (int i = 0; i < N; i++)
		bt.add(i, 1);
	int L = 0, R = N;
	while (Q--) {
		int q; scanf("%d", &q);
		if (q == 1) {
			int d; scanf("%d", &d);
			if (d * 2 > abs(L - R)) {
				swap(L, R);
				d = abs(L - R) - d;
			}
			if (L < R) {
				for (int i = L; i < L + d; i++)
					bt.add((L + d) * 2 - 1 - i, bt.get(i));
				L += d;
			}
			else {
				for (int i = L - 1; i >= L - d; i--)
					bt.add((L - d) * 2 - 1 - i, bt.get(i));
				L -= d;
			}
		}
		if (q == 2) {
			int l, r; scanf("%d%d", &l, &r);
			if (L < R) printf("%d\n", bt.sum(L + r) - bt.sum(L + l));
			else printf("%d\n", bt.sum(L - l) - bt.sum(L - r));
		}
	}
}