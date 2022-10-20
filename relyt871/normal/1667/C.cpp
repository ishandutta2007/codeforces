#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;

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

void solve() {
    int n; read(n);
    int ans = n - (n + 1) / 3;
    printf("%lld\n", ans);
    int i = 0, j = 0;
    for (i = 1, j = 1; j <= ans; ++i, j += 2) {
        printf("%d %d\n", i, j);
    }
    for (j = 2; j <= ans; ++i, j += 2) {
        printf("%d %d\n", i, j);
    }
}

int main() {
    solve();
    return 0;
}