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


void solve() {
    int n; read(n);
    printf("%d\n", (1 << n) - 1);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}