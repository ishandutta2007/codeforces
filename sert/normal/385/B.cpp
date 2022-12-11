#include <cstdio>
#include <cstring>
char s[10000];
int ans, n, kol;
int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = n - 4; i >= 0; i--) {
        if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r')
            kol = n - i - 3;
        ans += kol;
    }
    printf("%d\n", ans);
}