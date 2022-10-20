#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 200005;

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

int n, k, a[MAXN], ccnt[MAXN];
map<int, int> mp;

struct SegmentTree {
    int sum[MAXN << 2], cnt[MAXN << 2];

    void Build(int rt, int b, int e) {
        if (b == e) {
            cnt[rt] = ccnt[b];
            sum[rt] = cnt[rt] * b;
            return;
        }
        int mid = (b + e) >> 1;
        Build(lc, b, mid);
        Build(rc, mid + 1, e);
        sum[rt] = sum[lc] + sum[rc];
        cnt[rt] = cnt[lc] + cnt[rc];
    }

    void Update(int rt, int b, int e, int pos) {
        if (b == e) {
            cnt[rt] -= 1;
            sum[rt] -= b;
            return;
        }
        int mid = (b + e) >> 1;
        if (pos <= mid) Update(lc, b, mid, pos);
        else Update(rc, mid + 1, e, pos);
        sum[rt] = sum[lc] + sum[rc];
        cnt[rt] = cnt[lc] + cnt[rc];
    }

    int Query(int rt, int b, int e, int k) {
        if (b == e) {
            return k / b;
        }
        int mid = (b + e) >> 1;
        if (k <= sum[lc]) {
            return Query(lc, b, mid, k);
        } else {
            return cnt[lc] + Query(rc, mid + 1, e, k - sum[lc]);
        }
    }
} seg;

void solve() {
    read(n); read(k);
    mp.clear();
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        ++mp[a[i]];
        ccnt[i] = 0;
    }
    int dif = 0, mex = -1;
    for (auto x : mp) {
        ++ccnt[x.se];
        ++dif;
    }
    seg.Build(1, 1, n);
    int need = 0, ans = 1e9;
    for (int i = 0; i <= n; ++i) {
        int c = mp[i];
        if (!c) {
            if (mex == -1) {
                mex = i;
            }
        } else {
            seg.Update(1, 1, n, c);
        }
        if (!c) {
            ans = min(ans, dif - seg.Query(1, 1, n, k) + need - i);
            ++need;
        }
        if (need > k) break;
    }
    ans = min(ans, dif - mex);
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}