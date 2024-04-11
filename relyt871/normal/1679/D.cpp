#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
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

LL k;
int n, m, a[MAXN], b[MAXN], mx;
int deg[MAXN], dp[MAXN], q[MAXN], head, tail;
vector<int> g[MAXN];

bool Check() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        deg[i] = dp[i] = 0;
    }
    for (int u = 1; u <= n; ++u) {
        if (a[u] > mx) continue;
        ++cnt;
        for (auto v : g[u]) {
            if (a[v] > mx) continue;
            ++deg[v];
        }
    }
    head = 1, tail = 0;
    for (int i = 1; i <= n; ++i) {
        if (!deg[i] && a[i] <= mx) {
            dp[i] = 1;
            q[++tail] = i;
        }
    }
    while (head <= tail) {
        int u = q[head++];
        for (auto v : g[u]) {
            if (a[v] > mx) continue;
            dp[v] = max(dp[v], dp[u] + 1);
            if (--deg[v] == 0) {
                q[++tail] = v;
            }
        }
    }
    if (tail < cnt) {
        return 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (dp[i] >= k) return 1;
    }
    return 0;
}

void solve() {
    read(n); read(m); read(k);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        b[i] = a[i];
    }
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        g[u].push_back(v);
    }
    sort(b + 1, b + n + 1);
    int nn = unique(b + 1, b + n + 1) - (b + 1);
    int L = 1, R = n, ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        mx = b[mid];
        if (Check()) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    printf("%d\n", ans? b[ans] : -1);
}

int main() {
    solve();
    return 0;
}