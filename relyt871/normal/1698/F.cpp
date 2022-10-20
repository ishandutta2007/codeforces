#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 505;

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

int n, a[N], b[N];
vector<pii> ans;

inline void Rev(int l, int r) {
    reverse(a + l, a + r + 1);
    ans.push_back(make_pair(l, r));
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }
    ans.clear();
    if (a[1] != b[1] || a[n] != b[n]) {
        puts("NO");
        return;
    }
    for (int i = 2; i < n; ++i) {
        if (a[i] == b[i]) continue;
        int ok = 0, pos = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] == b[i] && a[j + 1] == a[i - 1]) {
                Rev(i - 1, j + 1);
                ok = 1;
                break;
            } else if (a[j] == a[i - 1] && a[j + 1] == b[i]) {
                pos = j;
            }
        }
        if (ok) continue;
        if (!pos) {
            puts("NO");
            return;
        }
        for (int j = i - 1; j <= pos && !ok; ++j) {
            for (int k = pos + 1; k <= n; ++k) {
                if (a[j] == a[k]) {
                    Rev(j, k);
                    ok = 1;
                    break;
                }
            }
        }
        if (!ok) {
            puts("NO");
            return;
        }
        for (int j = i; j < n; ++j) {
            if (a[j] == b[i] && a[j + 1] == a[i - 1]) {
                Rev(i - 1, j + 1);
                ok = 1;
                break;
            }
        }
    }
    puts("YES");
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.fi, p.se);
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}