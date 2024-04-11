#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
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

char a[100], b[100];
int n, m;

void solve() {
    read(n); read(m);
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    for (int i = m, j = n; i >= 2; --i, --j) {
        if (b[i] != a[j]) {
            puts("NO");
            return;
        }
    }
    bool has1 = 0, has0 = 0;
    for (int i = 1; i <= n - m + 1; ++i) {
        if (a[i] == '1') has1 = 1;
        if (a[i] == '0') has0 = 1;
    }
    if (b[1] == '0') puts(has0? "YES" : "NO");
    if (b[1] == '1') puts(has1? "YES" : "NO");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}