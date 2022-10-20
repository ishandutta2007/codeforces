#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

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

int Query(int w) {
    printf("? %d\n", w);
    fflush(stdout);
    int ret; read(ret);
    return ret;
}

void solve() {
    int n; read(n);
    int L = 1, R = n * 2022, S = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (Query(mid) == 1) {
            S = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    int ans = S;
    for (int i = 1; i <= n; ++i) {
        int h = Query(S / i);
        if (h) {
            ans = min(ans, h * (S / i));
        }
    }
    printf("! %d\n", ans);
    fflush(stdout);
}

int main() {
    solve();
    return 0;
}