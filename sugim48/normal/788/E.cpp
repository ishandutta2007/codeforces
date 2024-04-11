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
int INF = INT_MAX / 2;

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

int a[100000], al[100000], ar[100000];
bool pos[100000];

struct segtree {
	segtree *lch, *rch;
	int l, r;
	ll L, M, R, LM, MR, LMR;
	segtree(int _l, int _r) : l(_l), r(_r) {
		if (r - l == 1) return;
		int m = (l + r) / 2;
		lch = new segtree(l, m);
		rch = new segtree(m, r);
	}
	void update(int k, int i) {
		if (k < l || r <= k) return;
		if (r - l == 1) {
			L = pos[i] * al[i];
			M = pos[i] * 1;
			R = pos[i] * ar[i];
			LM = MR = LMR = 0;
			return;
		}
		lch->update(k, i);
		rch->update(k, i);
		L = (lch->L + rch->L) % MOD;
		M = (lch->M + rch->M) % MOD;
		R = (lch->R + rch->R) % MOD;
		LM = (lch->LM + rch->LM + lch->L * rch->M) % MOD;
		MR = (lch->MR + rch->MR + lch->M * rch->R) % MOD;
		LMR = (lch->LMR + rch->LMR + lch->L * rch->MR + lch->LM * rch->R) % MOD;
	}
};

int main() {
	int N; cin >> N;
	rep(i, N) scanf("%d", &a[i]);
	vector<int> A(a, a + N);
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	int M = A.size();
	rep(i, N) a[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin();
	{
		bit b(M);
		for (int i = 0; i < N; i++) {
			al[i] = b.sum(a[i] + 1);
			b.add(a[i], 1);
		}
	}
	{
		bit b(M);
		for (int i = N - 1; i >= 0; i--) {
			ar[i] = b.sum(a[i] + 1);
			b.add(a[i], 1);
		}
	}
	vector<int> num(M), index(N);
	rep(i, N) index[i] = num[a[i]]++;
	vector<segtree*> st(M);
	rep(x, M) if (num[x]) st[x] = new segtree(0, num[x]);
	rep(i, N) pos[i] = true, st[a[i]]->update(index[i], i);
	int ans = 0;
	rep(x, M) if (num[x]) ans = (ans + st[x]->LMR) % MOD;
	int Q; cin >> Q;
	while (Q--) {
		int q, i; scanf("%d%d", &q, &i); i--;
		pos[i] = !pos[i];
		ans = (ans + MOD - st[a[i]]->LMR) % MOD;
		st[a[i]]->update(index[i], i);
		ans = (ans + st[a[i]]->LMR) % MOD;
		printf("%d\n", ans);
	}
}