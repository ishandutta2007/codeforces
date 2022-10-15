#include <cstdio>

const int N = 300005;

int n, m, u, v, a[N], b[N];

bool solve(int x, int y) {
    for (int i = 1; i <= n; i++) {
        if (a[i] == x || b[i] == x || a[i] == y || b[i] == y) { continue; }
        return false;
    }
    return true;
}

bool check(int x) {
    for (int i = 1; i <= n; i++) {
        if (a[i] == x || b[i] == x) { continue; }
        return solve(x, a[i]) || solve(x, b[i]);
    }
    return true;
}

int main() {
    scanf("%d%d", &m, &n); 
    for (int i = 1; i <= n; i++) { scanf("%d%d", &a[i], &b[i]); }
    printf("%s\n", check(a[1]) || check(b[1]) ? "YES" : "NO");
    return 0;
}