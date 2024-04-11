#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

char t[MAXN], s[MAXN];
int n, used[26], ban[26], from[26], to[26];

void solve() {
    read(n);
    scanf("%s", t + 1);
    for (int i = 0; i < 26; ++i) {
        used[i] = 0;
        from[i] = to[i] = -1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int x = t[i] - 'a';
        if (from[x] == -1) {
            for (int i = 0; i < 26; ++i) {
                ban[i] = 0;
            }
            for (int i = 0; i < 26; ++i) {
                if (from[i] != -1) {
                    ban[from[i]] = 1;
                }
            }
            ban[x] = 1;
            if (cnt < 25) {
                int y = x;
                while (to[y] != -1) {
                    y = to[y];
                }
                ban[y] = 1;
            }
            for (int i = 0; i < 26; ++i) {
                if (!ban[i]) {
                    from[x] = i;
                    to[i] = x;
                    break;
                }
            }
            ++cnt;
        }
        s[i] = from[x] + 'a';
    }
    for (int i = 1; i <= n; ++i) {
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