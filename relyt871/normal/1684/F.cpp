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

int n, m, a[MAXN], b[MAXN], tot;
int nxt[MAXN], mov[MAXN], tag[MAXN];
int s[MAXN], top;
vector<int> pos[MAXN];
vector<int> vec[MAXN];

void solve() {
    read(n); read(m);
    tot = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        b[++tot] = a[i];
        nxt[i] = n + 1;
        tag[i] = mov[i] = 0;
        vec[i].clear();
        pos[i].clear();
    }
    sort(b + 1, b + tot + 1);
    tot = unique(b + tot, b + tot + 1) - (b + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
        pos[a[i]].push_back(i);
    }
    for (int i = 1, l, r; i <= m; ++i) {
        read(l); read(r);
        vec[l].push_back(r);
    }
    int far = 0, rmn = n + 1, lmx = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto r : vec[i]) {
            far = max(far, r);
        }
        if (!far) continue;
        int lp = lower_bound(pos[a[i]].begin(), pos[a[i]].end(), i) - pos[a[i]].begin();
        int rp = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), far) - pos[a[i]].begin() - 1;
        if (lp >= rp) continue;
        rmn = min(rmn, pos[a[i]][lp + 1]);
        lmx = max(lmx, pos[a[i]][rp - 1]);
        mov[i] = pos[a[i]][rp];
    }
    if (rmn == n + 1) {
        printf("0\n");
        return;
    }
    int ans = n;
    for (int i = 1; i <= rmn; ++i) {
        ans = min(ans, lmx - i + 1);
        lmx = max(lmx, mov[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}