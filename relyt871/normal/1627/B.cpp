#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 55;
const int MAXN = 500005;

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

int n, m, d[MAXN];

inline int D(int x, int y, int x2, int y2) {
    return abs(x - x2) + abs(y - y2);
}

void solve() {
    read(n); read(m);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[++tot] = max(max(D(i, j, 1, 1), D(i, j, 1, m)), max(D(i, j, n, 1), D(i, j, n, m)));
        }
    }
    sort(d + 1, d + tot + 1);
    for (int i = 1; i <= tot; ++i) {
        printf("%d ", d[i]);
    }
    printf("\n");
}

int main() {
	int T; read(T);
	while (T--) {
        solve();
	}
	return 0;
}