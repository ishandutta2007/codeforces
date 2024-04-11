#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<long long, int> pt;

long long inf = 1e18;

int n, m;
long long sum = 0;
int d[N], h[N];
long long p[N];
long long f[2][N];

pair<pt, pt> ma[2][888000];

pair<pt, pt> be(pair<pt, pt> a, pair<pt, pt> b) {
	if (a.F < b.F) swap(a, b);
	pair<pt, pt> ret;
	ret.F = a.F;
	ret.S = max(a.S, b.F);
	return ret;
}

void init(int pos, int l, int r) {
	if (l == r) {
		for (int i = 0; i < 2; i++) {
			ma[i][pos] = mp(mp(f[i][l], l), mp(-inf, -1) );
		}	
		return;
	}
	init(pos + pos, l, (l + r) / 2);
	init(pos + pos + 1, (l + r) / 2 + 1, r);

	for (int i = 0; i < 2; i++) {
		ma[i][pos] = be(ma[i][pos + pos], ma[i][pos + pos + 1]);
	}
}

pair<pt, pt> fin(int pos, int l, int r, int ll, int rr, int v) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return mp(mp(-inf, -1), mp(-inf, -1));
	if (l == ll && r == rr) return ma[v][pos];

	pair<pt, pt> q1 = fin(pos + pos, l, (l + r) / 2, ll, rr, v);
	pair<pt, pt> q2 = fin(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr, v);

	return be(q1, q2);
}

long long sol1(int l, int r) {
	if (l > r) return -inf;
	if (l == r) return -inf;
	pair<pt, pt> P = fin(1, 0, n - 1, l, r, 1);
	pair<pt, pt> M = fin(1, 0, n - 1, l, r, 0);

	if (P.F.S != M.F.S) return P.F.F + M.F.F;

	long long t1 = P.F.F + M.S.F;
	long long t2 = P.S.F + M.F.F;
	return max(t1, t2);
}

long long sol2(int x, int y) {
	if (x < 0 || y >= n) return -inf;
	pair<pt, pt> P = fin(1, 0, n - 1, 0, x, 1);
	pair<pt, pt> M = fin(1, 0, n - 1, y, n - 1, 0);

	return P.F.F + M.F.F + sum;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) scanf("%d", &d[i]), sum += d[i];
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);

	p[0] = 0;
	for (int i = 0; i < n; i++) p[i + 1] = p[i] + d[i];

	for (int i = 0; i < n; i++) {
		f[0][i] = 2 * 1ll * h[i] - p[i];
		f[1][i] = 2 * 1ll * h[i] + p[i];
	}
	init(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		long long ans = -inf;
		if (a <= b) {
			ans = max(ans, sol1(0, a - 1));
			ans = max(ans, sol1(b + 1, n - 1));
			ans = max(ans, sol2(a - 1, b + 1));
		} else {
			ans = max(ans, sol1(b + 1, a - 1));
		}
		printf("%I64d\n", ans);
	}

	return 0;
}