#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int MAXQ = 1000005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, q, p[MAXN], pos[MAXN];
int stk[MAXN], top, L[MAXN], R[MAXN], lmx[MAXN];
vector<int> d[MAXN];
vector<pii> upd[MAXN], qry[MAXN];
LL ans[MAXQ];

struct BIT {
	LL t1[MAXN], t2[MAXN];

	inline void add(int x, int v) {
		LL tmp = 1LL * x * v;
		for (int i = x; i <= n; i += (i & (-i))) {
			t1[i] += v;
			t2[i] += tmp;
		}
	}

	inline LL sum(int x) {
		LL r1 = 0, r2 = 0;
		for (int i = x; i; i -= (i & (-i))) {
			r1 += t1[i];
			r2 += t2[i];
		}
		return r1 * (x + 1) - r2;
	}

	inline void modify(int l, int r, int v) {
		add(l, v);
		if (r < n) add(r + 1, -v);
	}

	inline LL query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
} bit1, bit2;

void solve() {
    read(n); read(q);
    for (int i = 1; i <= n; ++i) {
        read(p[i]);
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (i * i + i > n) break;
        for (int j = i * i + i; j <= n; j += i) {
            d[j].push_back(i);
        }
    }
    stk[top = 0] = 0;
    for (int i = 1; i <= n; ++i) {
        while (top && p[i] > p[stk[top]])  {
            --top;
        }
        L[p[i]] = stk[top] + 1;
        stk[++top] = i;
    }
    stk[top = 0] = n + 1;
    for (int i = n; i >= 1; --i) {
        while (top && p[i] > p[stk[top]]) {
            --top;
        }
        R[p[i]] = stk[top] - 1;
        stk[++top] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int pi = pos[i];
        lmx[pi] = top = 0;
        bool flag = 0;
        for (auto x : d[i]) {
            int y = i / x;
            int px = min(pos[x], pos[y]), py = max(pos[x], pos[y]);
            if (L[i] <= px && py <= R[i]) {
                if (py <= pi) {
                    lmx[pi] = max(lmx[pi], px);
                    flag = 1;
                } else {
                    lmx[py] = min(px, pi);
                    stk[++top] = py;
                }
            }
        }
        if (flag) {
            stk[++top] = pi;
        }
        sort(stk + 1, stk + top + 1);
        stk[++top] = R[i] + 1;
        for (int j = 1, mx = 0; j <= top; ++j) {
            if (j > 1) {
                upd[mx].push_back(make_pair(stk[j - 1], stk[j] - 1));
                upd[L[i] - 1].push_back(make_pair(-stk[j - 1], stk[j] - 1));
            }
            mx = max(mx, lmx[stk[j]]);
        }
    }

    for (int i = 1, l, r; i <= q; ++i) {
        read(l); read(r);
        qry[l].push_back(make_pair(r, i));
    }
    for (int i = n; i >= 1; --i) {
        for (auto pr : upd[i]) {
            if (pr.fi > 0) {
                bit1.modify(pr.fi, pr.se, i);
                bit2.modify(pr.fi, pr.se, 1);
            } else {
                bit1.modify(-pr.fi, pr.se, -i);
                bit2.modify(-pr.fi, pr.se, -1);
            }
        }
        for (auto pr : qry[i]) {
            ans[pr.se] = bit1.query(i, pr.fi) - bit2.query(i, pr.fi) * (i - 1);
        }
    }
    for (int i = 1; i <= q; ++i) {
        printf("%lld\n", ans[i]);
    }
}

int main() {
    solve();
    return 0;
}