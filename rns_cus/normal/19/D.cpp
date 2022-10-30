#include <bits/stdc++.h> 
using namespace std;
#define N 400400

int n, m, x[N], y[N], id[N];
char oper[N][7];
map <int, int> mpx;
int rx[N];
set <int> s[N];
set <int> :: iterator it;

void prepare() {
	for (int i = 1; i <= m; i ++) id[i] = x[i];
	sort(id + 1, id + m + 1);
	n = unique(id + 1, id + m + 1) - id - 1;
	for (int i = 1; i <= n; i ++) mpx[id[i]] = i, rx[i] = id[i];
}

#define max(a, b) ((a) > (b) ? (a) : (b))

template <class T> void chkMax(T &a, T b) { if (a < b) a = b; }

struct RMQ_Tree {

	int Max[N << 1];

	void modify(int p, int v) {
		Max[p += n] = v;
		for (; p > 1; p >>= 1) Max[p >> 1] = max(Max[p], Max[p ^ 1]);
	}

	int queryValue(int p) { return Max[p + n]; }

	int aa[50], bb[50];

	int queryMax(int L, int R, int v) {
		int mx = 0, an = 0, bn = 0;
		for (L += n, R += n; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
			if (L & 1) {
				chkMax(mx, Max[L]);
				aa[an++] = L;
			}
			if (!(R & 1)) {
				chkMax(mx, Max[R]);
				bb[bn++] = R;
			}
		}
		if (mx <= v) return -1;
		int i, x;
		for (i = 0; i < an; i ++) if (Max[aa[i]] > v) break;
		if (i < an) x = aa[i];
		else {
			for (i = bn - 1; i >= 0; i --) if (Max[bb[i]] > v) break;
			x = bb[i];
		}
		while (x <= n) {
			if (Max[x << 1] > v) x <<= 1;
			else x = x << 1 | 1;
		}
		return x - n;
	}
} T;

int main() {
//	freopen("d.in", "r", stdin);
//	freopen("d.out", "w", stdout);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) scanf("%s %d %d", oper[i], &x[i], &y[i]);
	prepare();
	for (int i = 1; i <= m; i ++) {
		int xx = mpx[x[i]];
		if (oper[i][0] == 'a') {
			s[xx].insert(y[i]);
			it = s[xx].end();
			it --;
			int yy = *it;
			if (yy == y[i]) T.modify(xx, yy);
		}
		else if (oper[i][0] == 'r') {
			s[xx].erase(y[i]);
			if (!s[xx].size()) T.modify(xx, 0);
			else {
				it = s[xx].end();
				it --;
				int yy = *it;
				if (yy != y[i]) T.modify(xx, yy);
			}
		}
		else {
			int L = xx + 1, R = n;
			int k = T.queryMax(L, R, y[i]), yy = y[i] + 1;
			if (k == -1) {puts("-1"); continue;}
		///	it = lower_bound(s[k].begin(), s[k].end(), y[i] + 1); yy = *it;
			it = s[k].find(y[i] + 1);
			if (it == s[k].end())
				s[k].insert(y[i] + 1), it = s[k].find(y[i] + 1), it ++, yy = *it, s[k].erase(y[i] + 1);
			printf("%d %d\n", rx[k], yy);
		}
	}
	return 0;
}