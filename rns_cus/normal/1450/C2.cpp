#include <bits/stdc++.h>
using namespace std;

#define N 303

int n;
char s[N][N];

inline char conv(char c) {
    if (c == '.') return 0;
    if (c == 'X') return 1;
    if (c == 'O') return 2;
    assert(0);
}

void solve() {
    int tot = 0;
    for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) if (s[i][j] != '.') tot ++;
    int up = tot / 3;
    for (int c = 0; c < 3; c ++) {
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) if ((i + j + conv(s[i][j])) % 3 == c && s[i][j] != '.') cnt ++;
        }
        if (cnt <= up) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) if ((i + j + conv(s[i][j])) % 3 == c && s[i][j] != '.') s[i][j] ^= 'X' ^ 'O';
            }
            for (int i = 0; i < n; i ++) puts(s[i]);
            return;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) scanf("%s", s[i]);
        solve();
    }


    return 0;
}