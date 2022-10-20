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

int n, a[MAXN], ans[MAXN], suf[MAXN];

void solve() {
    read(n);
    bool all1 = 1, alln = 1;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        if (a[i] != 0) all1 = 0;
        if (a[i] != n) alln = 0;
    }
    if (all1) {
        for (int i = 1; i <= n; ++i) {
            printf("0 ");
        }
        printf("\n");
        return;
    }
    if (alln) {
        for (int i = 1; i <= n; ++i) {
            printf("1 ");
        }
        printf("\n");
        return;
    }
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
    }
    int cnt1 = (int)(sum / n), cnt0 = n - cnt1;
    suf[n + 1] = 0;
    for (int i = n, ptr = n + 1; i >= 2; --i) {
        while (ptr > i && cnt0 - suf[ptr] >= i) {
            --ptr;
        }
        if (a[i] - (ptr - i) == i - 1) {
            ans[i] = 1;
        } else {
            ans[i] = 0;
        }
        suf[i] = suf[i + 1] + (ans[i] == 0);
    }
    ans[1] = (a[1] > 0);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
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