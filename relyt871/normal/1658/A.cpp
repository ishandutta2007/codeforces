#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

char s[MAXN];
int n;

void solve() {
    read(n);
    scanf("%s", s + 1);
    int ans = 0, lst = -1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0') {
            if (lst != -1) {
                ans += max(0, 2 - (i - lst - 1));
            }
            lst = i;
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