#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 500005;

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

int n, ans[MAXN];
int ufs[MAXN];

inline int getf(int x) {
    return (ufs[x] == x)? x : ufs[x] = getf(ufs[x]);
}

struct Node {
    int l, r;
    bool operator < (const Node &rhs) const {
        return (r - l) < (rhs.r - rhs.l);
    }
} a[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i].l); read(a[i].r);
        ufs[i] = i;
    }
    sort(a + 1, a + n + 1);
    ufs[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i) {
        ans[i] = getf(a[i].l);
        ufs[ans[i]] = getf(ans[i] + 1);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d %d %d\n", a[i].l, a[i].r, ans[i]);
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}