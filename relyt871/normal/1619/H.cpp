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

int n, q, B, to[MAXN], fr[MAXN], g[MAXN];

void Update(int x) {
    int y = x;
    for (int i = 1; i <= B; ++i) {
        y = fr[y];
    }
    for (int i = 1; i <= B + 1; ++i) {
        g[y] = x;
        y = to[y];
        x = to[x];
    }
}

void solve() {
    read(n); read(q);
    B = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        read(to[i]);
        fr[to[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        g[i] = i;
        for (int j = 1; j <= B; ++j) {
            g[i] = to[g[i]];
        }
    }
    int type, x, y;
    while (q--) {
        read(type); read(x); read(y);
        if (type == 1) {
            swap(to[x], to[y]);
            fr[to[x]] = x;
            fr[to[y]] = y;
            Update(x);
            Update(y);
        } else {
            int ans = x;
            while (y >= B) {
                ans = g[ans];
                y -= B;
            }
            while (y--) {
                ans = to[ans];
            }
            printf("%d\n", ans);
        }
    }
}

int main() {
    solve();
    return 0;
}