#include <cstdio>

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int N = 200005;

int n, m, a[N], s[N], t[N];

void clear() {
    for (int i = 18; ~i; i--) { a[i] = 0; }
}
void insert(int x) {
    for (int i = 18; ~i; i--) {
        if (1 << i & x) {
            if (a[i]) { x ^= a[i]; }
            else { a[i] = x; break; }
        }
    }
}
bool query(int x) {
    for (int i = 18; ~i; i--) {
        if (1 << i & x) { x ^= a[i]; }
    }
    return x == 0;
}

void solve(int d) {
    clear();
    for (int i = 1; i <= n; i++) {
        if (s[i] < (1 << d + 1)) {
            if (!query(s[i])) { t[++m] = s[i]; insert(s[i]); }
        }
    }
    printf("%d\n", d);
    for (int i = 0, x; i < (1 << d); i++) {
        x = 0;
        for (int j = 0; j < d; j++) {
            if ((i >> j & 1) ^ (i >> (j + 1) & 1)) { x ^= t[j + 1]; }
        }
        printf("%d ", x);
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        s[i] = read(); insert(s[i]);
    }
    for (int i = 0; i <= 18; i++) {
        if (!query(1 << i)) { solve(i); break; }
    }
    return 0;
}