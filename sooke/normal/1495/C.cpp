#include <bits/stdc++.h>

const int N = 505;

int T, n, m;
char c[N][N];

struct Atom {
    int z, x, y;
};

bool operator <(const Atom &i, const Atom &j) {
    return i.z < j.z;
}

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%d%d", &n, &m);
        std::vector<Atom> a;
        for (int i = 1; i <= n; i++) {
            scanf("%s", c[i] + 1);
        }
        for (int i = 1; i <= n; i += 3) {
            for (int j = 1; j <= m; j++) {
                c[i][j] = 'X';
            }
            if (i + 3 > n) {
                if (n % 3 == 0) {
                    for (int j = 1; j <= m; j++) {
                        if (c[i + 2][j] == 'X') {
                            c[i + 1][j] = 'X';
                        }
                    }
                }
            } else {
                bool gg = true;
                for (int j = 1; j <= m; j++) {
                    if (c[i + 1][j] == 'X') {
                        c[i + 2][j] = 'X'; gg = false; break;
                    }
                    if (c[i + 2][j] == 'X') {
                        c[i + 1][j] = 'X'; gg = false; break;
                    }
                }
                if (gg) { c[i + 1][1] = c[i + 2][1] = 'X'; }
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%s\n", c[i] + 1);
        }
    }
    return 0;
}