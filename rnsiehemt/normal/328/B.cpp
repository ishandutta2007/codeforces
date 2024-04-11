#include <cstdio>
#include <cstring>
#include <algorithm>

const int inf = 2012012012;

int main()
{
    char t[8]; scanf(" %s", t); int M = strlen(t);
    char s[205]; scanf(" %s", s); int N = strlen(s);
    int c[11]; std::fill(c, c+10, 0);
    for (int i = 0; i < N; i++) c[s[i]-'0']++;
    c[2] += c[5]; c[6] += c[9];
    int d[11]; std::fill(d, d+10, 0);
    for (int i = 0; i < M; i++) d[t[i]-'0']++;
    d[2] += d[5]; d[6] += d[9];
    int max = inf;
    for (int i = 0; i < 10; i++) {
        if (i == 5 || i == 9) continue;
        if (d[i] == 0) continue;
        else max = std::min(max, c[i]/d[i]);
    }
    printf("%d\n", max);
}