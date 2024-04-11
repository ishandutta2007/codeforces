#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 10005;

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

int n, ans[MAXN], p[MAXN], qry[MAXN];

inline int Query(int a, int b, int c) {
    printf("? %d %d %d\n", a, b, c);
    fflush(stdout);
    int ret; read(ret); return ret;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        ans[i] = -1;
        p[i] = i;
    }
    p[n + 1] = 1;
    p[n + 2] = 2;
    p[n + 3] = 3;
    for (int i = 1; i <= n - 2; ++i) {
        qry[i] = Query(i, i + 1, i + 2);
    }
    qry[n - 1] = Query(n - 1, n, 1);
    qry[n] = Query(n, 1, 2);
    qry[n + 1] = qry[1];
    for (int i = 1; i <= n; ++i) {
        if (qry[i] ^ qry[i + 1]) {
            int x = p[i], y = p[i + 3];
            ans[x] = qry[i];
            ans[y] = qry[i + 1];
            for (int j = 1; j <= n; ++j) {
                if (j == x || j == y) continue;
                ans[j] = Query(j, x, y);
            }
            int cnt = 0;
            for (int j = 1; j <= n; ++j) {
                cnt += (ans[j] == 0);
            }
            printf("! %d", cnt);
            for (int j = 1; j <= n; ++j) {
                if (ans[j] == 0) {
                    printf(" %d", j);
                }
            }
            printf("\n");
            fflush(stdout);
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