#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 305;

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

int n, a[N];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int ans = 2e9;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                ans = min(ans, abs(a[j] - a[i]) + abs(a[k] - a[i]));
                ans = min(ans, abs(a[i] - a[j]) + abs(a[k] - a[j]));
                ans = min(ans, abs(a[i] - a[k]) + abs(a[j] - a[k]));
            }
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