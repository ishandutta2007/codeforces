#include <cstdio>
#include <cstring>

int N, M;
char s[2005];

int main()
{
    scanf("%d %s", &N, s); M = strlen(s);
    int ans = 0; for (int i = N; i < M; i += N) ans += (s[i-1] == s[i-2] && s[i-2] == s[i-3]);
    printf("%d\n", ans);
}