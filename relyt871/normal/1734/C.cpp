#include <bits/stdc++.h>
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

char T[MAXN];
int n;

void solve() {
    read(n);
    scanf("%s", T + 1);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n && T[j] != '1'; j += i) {
            ans += (T[j] == '0'? i : 0);
            T[j] = '2';
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}