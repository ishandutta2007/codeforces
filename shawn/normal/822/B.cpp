#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, ans = 0x7f7f7f7f, id;
char s[1010], t[1010];

int main() {
    scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
    for (int i = 1; i + n - 1 <= m; i ++) {
        int tm = 0;
        for (int j = 1; j <= n; j ++) tm += t[i + j - 1] != s[j];
        if (tm < ans) ans = tm, id = i;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i ++) if (s[i] != t[id + i - 1]) printf("%d ", i);
    return puts(""), 0;
}