#include <cstdio>
#include <cstring>

int N;
char s[100005];
bool f[12];
int q, a = 1, b = 10;

int main()
{
    scanf("%s", s); N = strlen(s);
    for (int i = 0; i < N; i++) q += (s[i] == '?');
    for (int i = 0; i < N; i++) if ('A' <= s[i] && s[i] <= 'J') f[s[i]-'A'] = true;
    for (int i = 0; 'A'+i <= 'J'; i++) if (f[i]) a *= (b--);
    if (s[0] == '?') { q--; a *= 9; }
    if ('A' <= s[0] && s[0] <= 'J') a = a/10*9;
    printf("%d", a); while (q--) { printf("0"); } printf("\n");
}