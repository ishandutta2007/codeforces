#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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
    int x, y;
    read(x); read(y);
    if (x == 0 && y == 0) {
        printf("0\n");
        return;
    }
    int sum = x * x + y * y;
    int z = sqrt(sum);
    for (int i = z - 2; i <= z + 2; ++i) {
        if (z * z == sum) {
            printf("1\n");
            return;
        }
    }
    printf("2\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}