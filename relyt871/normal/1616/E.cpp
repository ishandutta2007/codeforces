#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
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

int n, cnt[26], pos[26][MAXN], used[26];
char s[MAXN], t[MAXN];

struct BIT {
    int tr[MAXN];
    inline void clean() {
        for (int i = 1; i <= n; ++i) {
            tr[i] = 0;
        }
    }
    inline void add(int x) {
        for (; x <= n; x += (x & (-x))) {
            ++tr[x];
        }
    }
    inline int sum(int x) {
        int ret = 0;
        for (; x; x -= (x & (-x))) {
            ret += tr[x];
        }
        return ret;
    }
} bit;

void solve() {
    read(n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    mset(cnt, 0);
    for (int i = 1; i <= n; ++i) {
        int c = s[i] - 'a';
        pos[c][++cnt[c]] = i;
    }
    LL ans = 3LL * n * n, cur = 0;
    mset(used, 0);
    bit.clean();
    for (int i = 1; i <= n; ++i) {
        int c = t[i] - 'a';
        for (int j = 0; j < c; ++j) {
            if (used[j] == cnt[j]) continue;
            int p = pos[j][used[j] + 1];
            int dis = p - i + bit.sum(n - p);
            ans = min(ans, cur + dis);
        }
        if (used[c] == cnt[c]) break;
        int p = pos[c][used[c] + 1];
        int dis = p - i + bit.sum(n - p);
        cur += dis;
        ++used[c];
        bit.add(n - p + 1);
    }
    if (ans == 3LL * n * n) {
        puts("-1");
    } else {
        printf("%lld\n", ans);
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}