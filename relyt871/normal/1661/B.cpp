#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 40005;
const int MOD = 32767;

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

inline int Calc(int x) {
    if (x == 0) return 0;
    for (int i = 1; ; ++i) {
        x = (x * 2) & MOD;
        if (x == 0) return i;
    }
}

int ans[MAXN];

void solve() {
    for (int i = 0; i <= MOD; ++i) {
        ans[i] = 15;
        for (int j = 0; j <= 14; ++j) {
            ans[i] = min(ans[i], j + Calc((i + j) & MOD));
        }
    }
    int n; read(n);
    for (int i = 1; i <= n; ++i) {
        int a; read(a);
        printf("%d ", ans[a]);
    }
}

int main() {
    solve();
    return 0;
}