#include <cstdio>
#include <cstring>
char s[1234567];
long long n, r, q;
int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
        if (s[i] == '^')
            r = i;
    for (int i = 0; i < n; i++)
        if (s[i] >= '0' && s[i] <= '9')
            q += (i - r) * (s[i] - '0');
    if (q < 0) printf("left\n");
    if (q == 0) printf("balance\n");
    if (q > 0) printf("right\n");
}