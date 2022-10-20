#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100005;

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

char s[MAXN];
int n, pre[MAXN];

inline bool same(int l, int r) {
    return pre[r] <= l;
}

void solve() {
    read(n);
    scanf("%s", s + 1);
    for (int i = 1, j; i <= n; i = j + 1) {
        for (j = i; j < n && s[j + 1] == s[i]; ++j);
        for (int k = i; k <= j; ++k) {
            pre[k] = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i <= n / 2) {
            ans += same(i + 1, n - i + 1);
        } else if (i * 2 - 1 == n) {
            ++ans;
        } else {
            ans += same(n - i + 1, i - 1);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}