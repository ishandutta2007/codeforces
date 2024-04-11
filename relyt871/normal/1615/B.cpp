#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

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

int cnt[MAXN][20];

void prework() {
    for (int i = 1; i <= 200000; ++i) {
        for (int j = 0; j < 20; ++j) {
            cnt[i][j] = cnt[i - 1][j] + ((i >> j) & 1);
        }
    }
}

void solve() {
    int l, r;
    read(l); read(r);
    int ans = 0;
    for (int i = 0; i < 20; ++i) {
        ans = max(ans, cnt[r][i] - cnt[l - 1][i]);
    }
    printf("%d\n", r - l + 1 - ans);
}

int main() {
    prework();
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}