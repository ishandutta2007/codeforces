#include <cstdio>
#include <cstring>
char s[1234567];
int a[1234567], n, len, uk;
long long ans;
int main() {
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n - 4; i++)
        if (s[i] == 'm' && s[i + 1] == 'e' && s[i + 2] == 't' && s[i + 3] == 'a' && s[i + 4] == 'l')
            a[len++] = i;
    for (int i = 0; i < n - 4; i++) {
        if (uk < len) if (a[uk] < i + 5) uk++;
        if (s[i] == 'h' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'v' && s[i + 4] == 'y')
            ans += (len - uk);
    }
    printf("%I64d\n", ans);
}