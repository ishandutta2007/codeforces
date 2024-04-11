#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
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

int n, a[MAXN], m, sor[MAXN], cnt[MAXN], rnk[MAXN], ans[MAXN];
vector<int> pos[MAXN];

inline bool cmp(int x, int y) {
    return cnt[x] > cnt[y];
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        pos[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        pos[a[i]].push_back(i);
    }
    m = 0;
    for (int i = 1; i <= n; ++i) {
        if (pos[i].size()) {
            sor[++m] = i;
            cnt[i] = pos[i].size();
        }
    }
    sor[m + 1] = cnt[0] = 0;
    sort(sor + 1, sor + m + 1, cmp);
    for (int i = 1; i <= m; ++i) {
        rnk[sor[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int x = sor[i], y = sor[i + 1];
        for (int j = 1; j <= cnt[x]; ++j) {
            if (j <= cnt[y]) {
                ans[pos[x][j - 1]] = a[pos[y][j - 1]];
            } else {
                ans[pos[x][j - 1]] = a[pos[sor[1]][j - 1]];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}