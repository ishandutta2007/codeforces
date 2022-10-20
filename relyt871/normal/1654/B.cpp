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
int n, cnt[26];

void solve() {
    mset(cnt, 0);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[s[i] - 'a'] == 1) {
            p = i; break;
        }
        --cnt[s[i] - 'a'];
    }
    for (int i = p; i <= n; ++i) {
        putchar(s[i]);
    }
    puts("");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}