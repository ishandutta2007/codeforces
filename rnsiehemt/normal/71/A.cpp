#include <cstdio>
#include <cstring>

int N, M;
char s[105];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %s", s); M = strlen(s);
        if (M > 10) printf("%c%d%c\n", s[0], M-2, s[M-1]);
        else printf("%s\n", s);
    }
}