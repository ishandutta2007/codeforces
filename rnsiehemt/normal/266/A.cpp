#include <cstdio>

char s[55];
int A;

int main() {
    scanf("%*d %s", s);
    for (int i = 1; s[i]; i++) if (s[i] == s[i-1]) A++;
    printf("%d\n", A);
}