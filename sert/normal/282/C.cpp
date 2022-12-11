#include <cstdio>
#include <cstring>
char s[1234456], k[1234456];
int n, m, a1, a2;
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%s%s", s, k);
    n = strlen(s);
    m = strlen(k);
    for (int i = 0; i < n; i++) a1 += s[i] - '0';
    for (int i = 0; i < m; i++) a2 += k[i] - '0';
    if (n == m && !!a1 == !!a2) printf("YES\n");
    else printf("NO\n");
}