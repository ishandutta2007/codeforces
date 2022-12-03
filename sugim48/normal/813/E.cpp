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

int unique(vector<int>& a) {
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	return a.size();
}
 
struct bit {
	int n; vector<int> a;
	bit(int n) : n(n), a(n + 1) {}
	ll sum(int i) {
		int x = 0;
		for (; i; i -= i & -i) x += a[i];
		return x;
	}
	void add(int i, int x) {
		for (i++; i <= n; i += i & -i) a[i] += x;
	}
};
 
struct unko {
	int l, r, n;
	vector<int> a;
	bit *b;
	unko *lch, *rch;
	unko(int _l, int _r, vector<vector<int> >& _a) : l(_l), r(_r) {
		if (r - l == 1) a = _a[l];
		else {
			lch = new unko(l, (l + r) / 2, _a);
			rch = new unko((l + r) / 2, r, _a);
			vector<int> &la = lch->a, &ra = rch->a;
			for (int x: la) a.push_back(x);
			for (int x: ra) a.push_back(x);
		}
		n = unique(a);
		b = new bit(n);
	}
	int sum(int i, int j, int k) {
		if (j <= l || r <= i) return 0;
		if (i <= l && r <= j) {
			int _k = lower_bound(a.begin(), a.end(), k) - a.begin();
			return b->sum(_k);
		}
		return lch->sum(i, j, k) + rch->sum(i, j, k);
	}
	void add(int i, int k, int x) {
		if (i < l || r <= i) return;
		int _k = lower_bound(a.begin(), a.end(), k) - a.begin();
		b->add(_k, x);
		if (r - l == 1) return;
		lch->add(i, k, x); rch->add(i, k, x);
	}
};

int main() {
	int N, K; cin >> N >> K;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]), a[i]--;
	vector<vector<int> > v(100000);
	rep(i, N) v[a[i]].pb(i);
	vector<vector<int> > _a(N + 1);
	rep(x, 100000)
		for (int k = 0; k + K < v[x].size(); k++) {
			int l = v[x][k], r = v[x][k + K] + 1;
			_a[l].pb(r);
		}
	unko *z = new unko(0, N + 1, _a);
	rep(x, 100000)
		for (int k = 0; k + K < v[x].size(); k++) {
			int l = v[x][k], r = v[x][k + K] + 1;
			z->add(l, r, 1);
		}
	int Q; cin >> Q;
	int last = 0;
	while (Q--) {
		int l, r; scanf("%d%d", &l, &r);
		l = (l + last) % N + 1;
		r = (r + last) % N + 1;
		if (l > r) swap(l, r);
		l--;
		last = r - l - z->sum(l, N + 1, r + 1);
		printf("%d\n", last);
	}
}