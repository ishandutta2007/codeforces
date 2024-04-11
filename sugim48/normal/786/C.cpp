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
struct edge { int u, v; ll w; };

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
	int lower_bound(ll x) {
		if (x <= 0) return 0;
		int res = 0;
		for (int i = 1 << 24; i > 0; i >>= 1)
			if (res + i < v.size() && v[res + i] < x) {
				res += i; x -= v[res];
			}
		return res + 1;
	}
};

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]), a[i]--;
	vector<queue<int> > q(N);
	rep(i, N) q[a[i]].push(i);
	bit b(N);
	rep(x, N) if (!q[x].empty()) {
		int i = q[x].front(); q[x].pop();
		b.add(i, 1);
	}
	vector<vector<int> > v(N + 1);
	for (int k = 1; k <= N; k++) v[0].pb(k);
	vector<int> ans(N + 1);
	rep(l, N) {
		for (int k: v[l]) {
			int r = b.lower_bound(k + 1) - 1;
			v[r].pb(k);
			ans[k]++;
		}
		b.add(l, -1);
		int x = a[l];
		if (!q[x].empty()) {
			int i = q[x].front(); q[x].pop();
			b.add(i, 1);
		}
	}
	for (int k = 1; k <= N; k++)
		printf("%d ", ans[k]);
	cout << endl;
}