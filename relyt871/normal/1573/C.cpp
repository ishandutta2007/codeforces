#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

int n, deg[MAXN], dp[MAXN];
vector<int> g[MAXN];
priority_queue< int, vector<int>, greater<int> > pq[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        deg[i] = 0;
        dp[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        int k; read(k);
        for (int j = 1; j <= k; ++j) {
            int x; read(x);
            g[x].push_back(i);
            ++deg[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        while (!pq[i].empty()) {
            pq[i].pop();
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) {
            pq[1].push(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        while (!pq[i].empty()) {
            int u = pq[i].top();
            pq[i].pop();
            dp[u] = i;
            for (auto v : g[u]) {
                if (--deg[v] == 0) {
                    pq[i + (u > v)].push(v);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == -1) {
            puts("-1");
            return;
        }
        ans = max(ans, dp[i]);
        //printf("%d\n", dp[i]);
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