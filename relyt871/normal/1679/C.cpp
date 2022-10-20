#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100005;

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

int n, q, rcnt[MAXN], ccnt[MAXN];

struct BIT {
    int tr[MAXN];

    inline void add(int x, int v) {
        for (; x <= n; x += (x & (-x))) {
            tr[x] += v;
        }
    }

    inline int sum(int x) {
        int ret = 0;
        for (; x; x -= (x & (-x))) {
            ret += tr[x];
        }
        return ret;
    }

    inline int qry(int l, int r) {
        return sum(r) - sum(l - 1);
    }
} bit1, bit2;

void solve() {
    read(n); read(q);
    int t, x, y, x2, y2;
    while (q--) {
        read(t); read(x); read(y);
        if (t == 1) {
            if (++rcnt[x] == 1) {
                bit1.add(x, 1);
            }
            if (++ccnt[y] == 1) {
                bit2.add(y, 1);
            }
        } else if (t == 2) {
            if (--rcnt[x] == 0) {
                bit1.add(x, -1);
            }
            if (--ccnt[y] == 0) {
                bit2.add(y, -1);
            }
        } else if (t == 3) {
            read(x2); read(y2);
            if (bit1.qry(x, x2) == x2 - x + 1 ||
                bit2.qry(y, y2) == y2 - y + 1) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
}

int main() {
    solve();
    return 0;
}