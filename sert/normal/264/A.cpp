#include <cstdio>
#include <cstring>
char s[1234567];
int cb, ce, ans[1234567], n;
int main() {
    scanf("%s", s);
    n = strlen(s);
    ce = n - 1;
    for (int i = 0; i < n; i++)
        ans[(s[i] == 'l' ? ce-- : cb++)] = i + 1;
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
}