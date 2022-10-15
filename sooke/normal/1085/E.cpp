#include <cstdio>
#include <cstring>

const int N = 1000005;

int T, n, m;
char e, c[256], s[256], _c[256], _s[256], p[N], a[N], b[N];

inline bool add(char x, char y) {
    if (c[x] != ' ' || s[y] != ' ') { return c[x] == y; }
    c[x] = y; s[y] = x; return true;
}

bool solve1(int u) {
    if (c[p[u]] != ' ') { return a[u] < c[p[u]] && c[p[u]] < b[u]; }
    for (char i = a[u] + 1; i < b[u]; i++) {
        if (s[i] == ' ') { add(p[u], i); return true; }
    }
    return false;
}
bool solve2(int u) {
    if (!add(p[u], a[u])) { return false; }
    for (int i = u + 1; i < n; i++) {
        bool flag = true;
        for (char j = e; j >= a[i]; j--) {
            if (add(p[i], j)) {
                if (j == a[i]) { flag = false; } else { return true; }
            }
        }
        if (flag) { return false; }
    }
    return true;
}
bool solve3(int u) {
    if (!add(p[u], b[u])) { return false; }
    for (int i = u + 1; i < n; i++) {
        bool flag = true;
        for (char j = 'a'; j <= b[i]; j++) {
            if (add(p[i], j)) {
                if (j == b[i]) { flag = false; } else { return true; }
            }
        }
        if (flag) { return false; }
    }
    return true;
}

bool check() {
    for (char i = 'a'; i <= e; i++) { c[i] = ' '; s[i] = ' '; }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (!add(p[i], a[i])) { return false; }
        } else {
            if (solve1(i)) { break; }
            for (int j = 'a'; j <= e; j++) { _c[j] = c[j]; _s[j] = s[j]; }
            if (solve2(i)) { break; }
            for (int j = 'a'; j <= e; j++) { c[j] = _c[j]; s[j] = _s[j]; }
            if (solve3(i)) { break; }
            return false;
        }
    }
    for (char i = 'a', j = 'a'; i <= e; i++) {
        if (c[i] == ' ') {
            while (s[j] != ' ') { j++; }
            c[i] = j; s[j] = i;
        }
    }
    return true;
}

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%d%s%s%s", &m, p, a, b); n = strlen(p); e = 'a' + m - 1;
        if (check()) {
            printf("YES\n");
            for (int i = 'a'; i <= e; i++) { putchar(c[i]); } putchar('\n');
        } else { printf("NO\n"); }
    }
    return 0;
}