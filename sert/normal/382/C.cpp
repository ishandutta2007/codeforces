#include <cstdio>
#include <algorithm>
const int N = 1e5 + 34;
int n, a[N], md, ps = -1;
void finish() {
    std::exit(0);
    while (true);
}
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    std::sort(a, a + n);
    if (n == 1) {
        printf("-1\n");
        finish();
    }
    if (a[n - 1] == a[0]) {
        printf("1\n%d\n", a[0]);
        finish();
    }
    if (n == 2) {
        if (a[0] == a[1]) {
            printf("1\n%d\n", a[0]);
            finish();
        }
        if ((a[1] - a[0]) % 2)
            printf("2\n%d %d\n", a[0] + a[0] - a[1], a[1] + a[1] - a[0]);
        else
            printf("3\n%d %d %d\n", a[0] + a[0] - a[1], (a[0] + a[1]) / 2, a[1] + a[1] - a[0]);
        finish();
    }
    md = a[1] - a[0];
    for (int i = 2; i < n; i++)
        if (a[i] - a[i - 1] < md)
            md = a[i] - a[i - 1];
    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] != md) {
            if (ps != -1) {
                printf("0\n");
                finish();
            } else 
                ps = i;
        }
    if (ps == -1)
        printf("2\n%d %d\n", a[0] - md, a[n - 1] + md);
    else if (a[ps] - a[ps - 1] == md * 2)
        printf("1\n%d\n", (a[ps] + a[ps - 1]) / 2);
    else 
        printf("0\n");
    finish();
}