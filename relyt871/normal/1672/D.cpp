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

int n, a[MAXN], b[MAXN], cnt[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }
    for (int i = 1, j = 1; i <= n; ++i) {
        if (a[i] == b[j]) {
            ++j;
            while (j <= n && a[i] == b[j] && cnt[a[i]] > 0) {
                --cnt[a[i]];
                ++j;
            }
        } else {
            ++cnt[a[i]];
        }
    }
    bool ok = 1;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) ok = 0;
    }
    puts(ok? "YES" : "NO");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}