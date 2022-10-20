#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

int lg2[MAXN], need[MAXN];
int n, a[MAXN], lef[MAXN];
int s[MAXN], t;

inline bool same(int l, int r) {
    return (lef[r] <= l);
}

void solve() {
    read(n);
    for (int i = 1; i <= n ;++i) {
        read(a[i]);
    }
    a[n + 1] = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i - 1]) lef[i] = i;
        else lef[i] = lef[i - 1];
    }
    int ans = 2 + need[n];
    if (n > 1) {
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i + 1]) {
                ans = min(ans, 1 + need[i] + need[n - i]);
            }
        }
    }
    if (n > 2) {
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i + 1]) {
                t = 0;
                for (int j = 0; i + (1 << j) < n; ++j) {
                    s[++t] = i + (1 << j);
                    s[++t] = n - (1 << j);
                }
                sort(s + 1, s + t + 1);
                t = unique(s + 1, s + t + 1) - (s + 1);
                for (int j = 1; j <= t; ++j) {
                    if (a[s[j]] != a[s[j] + 1]) {
                        ans = min(ans, need[i] + need[s[j] - i] + need[n - s[j]]);
                    }
                }
                for (int j = 1; j < t; ++j) {
                    if (s[j] + 1 != s[j + 1]) {
                        if (!same(s[j] + 1, s[j + 1])) {
                            ans = min(ans, need[i] + need[s[j] + 1 - i] + need[n - s[j] - 1]);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    for (int i = 2; i <= 200000; ++i) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    for (int i = 1; i <= 200000; ++i) {
        if (i == (1 << lg2[i])) {
            need[i] = 0;
        } else {
            need[i] = (1 << (lg2[i] + 1)) - i;
        }
    }
	int T; read(T);
	while (T--) {
        solve();
	}
	return 0;
}