#include <cstdio>
int a[5], ans;
char ch;
int main() {
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    while (scanf("%c", &ch) != -1)
        ans += a[ch - '1'];
    printf("%d\n", ans);
}