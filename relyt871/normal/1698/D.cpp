#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 1000006;

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

bool Query(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        int x; read(x);
        cnt += (l <= x && x <= r);
    }
    return (cnt & 1);
}

void Work(int l, int r) {
    if (l == r) {
        printf("! %d\n", l);
        fflush(stdout);
        return;
    }
    int mid = (l + r) >> 1;
    if (Query(l, mid)) {
        Work(l, mid);
    } else {
        Work(mid + 1, r);
    }
}

void solve() {
    int n; read(n);
    Work(1, n);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}