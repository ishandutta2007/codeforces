#include <cstdio>
#include <cstring>

const int m = 1000000007;

int n;
int p[205];
char s[105];

int main()
{
    p[0] = 1; for (int i = 0; i < 200; i++) p[i+1] = (p[i]+p[i]) % m;
    scanf(" %s", s); n = strlen(s);
    
    int ans = 0;
    for (int k = 0; k < n; k++) if (s[k] == '1') ans = (ans + p[n+n-k-2]) % m;
    printf("%d\n", ans);
}