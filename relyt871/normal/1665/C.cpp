#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 1000006;

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

int n, deg[MAXN], m, a[MAXN];

inline bool degcmp(int x, int y) {
    return (deg[x] > deg[y]);
}

priority_queue<int> pq;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        deg[i] = 0;
    }
    deg[0] = 1;
    for (int i = 2; i <= n; ++i) {
        int fa; read(fa);
        ++deg[fa];
    }
    m = 0;
    for (int i = 0; i <= n; ++i) {
        if (deg[i]) {
            a[++m] = i;
        }
    }
    sort(a + 1, a + m + 1, degcmp);

    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = 1; i <= m; ++i) {
        pq.push(i + deg[a[i]] - 1);
    }
    if (pq.top() <= m) {
        printf("%d\n", m);
        return;
    }
    for (int i = m + 1; ; ++i) {
        int u = pq.top();
        pq.pop();
        pq.push(u - 1);
        if (pq.top() <= i) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}