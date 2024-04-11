#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef __int128 LL;
const int N = 1005;
const int B = 1023;
const int M = 2055;

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

template <typename T> inline void write(T WOW) {
    if (WOW > 9) {
        write(WOW / 10);
    }
    putchar(WOW % 10 + '0');
}

int n, m;
LL a[N], b[N];

struct SegmentTree {
    LL seg[M];

    void Build(int len, LL x, LL *y) {
        mset(seg, 0);
        for (int i = 1; i <= len; ++i) {
            seg[B + i] = x / __gcd(x, y[i]);
        }
        for (int i = B; i >= 1; --i) {
            seg[i] = __gcd(seg[i << 1], seg[i << 1 | 1]);
        }
    }

    void Update(int p) {
        seg[p += B] = 0;
        for (p >>= 1; p; p >>= 1) {
            seg[p] = __gcd(seg[p << 1], seg[p << 1 | 1]);
        }
    }
} ta[N], tb[N];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for(int i = 1; i <= m; ++i) {
        read(b[i]);
    }

    for (int i = 1; i <= n; ++i) {
        ta[i].Build(m, a[i], b);
    }
    for (int i = 1; i <= m; ++i) {
        tb[i].Build(n, b[i], a);
    }
    while (1) {
        bool flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] && ta[i].seg[1] > 1) {
                a[i] = 0;
                for (int j = 1; j <= m; ++j) {
                    if (b[j]) {
                        tb[j].Update(i);
                    }
                }
                flag = 1;
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (b[i] && tb[i].seg[1] > 1) {
                b[i] = 0;
                for (int j = 1; j <= n; ++j) {
                    if (a[j]) {
                        ta[j].Update(i);
                    }
                }
                flag = 1;
            }
        }
        if (!flag) break;
    }

    vector<LL> aans, bans;
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            aans.push_back(a[i]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (b[i]) {
            bans.push_back(b[i]);
        }
    }
    if (aans.empty() || bans.empty()) {
        puts("NO");
        return;
    }
    puts("YES");
    printf("%d %d\n", aans.size(), bans.size());
    for (auto x : aans) {
        write(x);
        putchar(' ');
    }
    puts("");
    for (auto x : bans) {
        write(x);
        putchar(' ');
    }
    puts("");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}