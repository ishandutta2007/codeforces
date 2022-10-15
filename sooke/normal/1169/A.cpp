#include <cstdio>

int n, u, v, s, t;
bool ans;

int main() {
    scanf("%d%d%d%d%d", &n, &u, &v, &s, &t);
    for (u--, v--, s--, t--; ; u = (u + 1) % n, s = (s + n - 1) % n) {
        ans |= u == s;
        if (u == v || s == t) { break; }
    }
    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}