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

int n, a[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int L = -1, R = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i + 1]) {
            L = i;
            break;
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] == a[i + 1]) {
            R = i;
            break;
        }
    }
    if (R == L) {
        printf("0\n");
    } else {
        printf("%d\n", R - L - (R != L + 1));
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}