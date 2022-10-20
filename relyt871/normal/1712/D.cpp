#include<bits/stdc++.h>
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

int n, k, a[MAXN], b[MAXN];

bool Check(int mid) {
    int use = 0;
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
        if (b[i] * 2 < mid) {
            b[i] = 1e9;
            ++use;
        }
    }
    int adj = 2;
    for (int i = 1; i < n; ++i) {
        adj = min(adj, (b[i] < mid) + (b[i + 1] < mid));
    }
    return (use + adj <= k);
}

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int L = 1, R = 1e9, ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (Check(mid)) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
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