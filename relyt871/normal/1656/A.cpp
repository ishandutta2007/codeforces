#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

int n, a[MAXN], b[MAXN];

inline bool cmp(int x, int y) {
    return a[x] < a[y];
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        b[i] = i;
    }
    sort(b + 1, b + n + 1, cmp);
    printf("%d %d\n", b[1], b[n]);

}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}