#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 1000005;
const LL MX = 1e9;

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

int n;
LL a[MAXN];

void solve() {
    read(n);
    a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        a[i] = a[i - 1] * 3;
        if (a[i] > MX) {
            puts("NO");
            return;
        }
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}