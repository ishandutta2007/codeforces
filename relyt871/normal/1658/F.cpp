#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 500005;

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

char s[MAXN];
int n, m;

void solve() {
    read(n); read(m);
    scanf("%s", s + 1);
    int cute = 0;
    for (int i = 1; i <= n; ++i) {
        cute += (s[i] == '1');
        s[n + i] = s[i];
    }
    if (1LL * cute * m % n) {
        puts("-1");
        return;
    }
    cute = 1LL * cute * m / n;
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        sum += (s[i] == '1');
    }
    for (int i = 1; i <= n; ++i) {
        if (sum == cute) {
            if (i + m - 1 <= n) {
                printf("1\n%d %d\n", i, i + m - 1);
            } else {
                printf("2\n%d %d\n%d %d\n", 1, i + m - 1 - n, i, n);
            }
            return;
        }
        sum -= (s[i] == '1');
        sum += (s[i + m] == '1');
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}