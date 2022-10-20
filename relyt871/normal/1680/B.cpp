#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
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

char g[10][10];
int n, m;

void solve() {
    read(n); read(m);
    int mn1 = n + 1, mn2 = m + 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", g[i] + 1);
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == 'R') {
                mn1 = min(mn1, i);
                mn2 = min(mn2, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == 'R' && i == mn1 && j == mn2) {
                puts("YES");
                return;
            }
        }
    }
    puts("NO");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}