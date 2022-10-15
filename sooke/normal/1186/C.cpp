#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

const int N = 1e6 + 5;

int n, m, ans, cnt, s[N];
char a[N], b[N];

int main() {
    scanf("%s%s", a + 1, b + 1); n = strlen(a + 1); m = strlen(b + 1);
    for (int i = 1; i <= n; i++) { s[i] = s[i - 1] + a[i] - '0'; }
    for (int i = 1; i <= m; i++) { cnt += b[i] - '0'; }
    for (int i = 1; i <= n - m + 1; i++) { ans += (s[i + m - 1] - s[i - 1] - cnt) % 2 == 0; }
    printf("%d\n", ans);
    return 0;
}