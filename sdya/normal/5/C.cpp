#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

char s[1100000];
int d[1100000];
int r[1100000];
int n = 0, m = 0;
int best = 0;



int main()
{
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n; i ++)
        if (s[i] == '(') m ++, d[i] = m; else m --, d[i] = m;

    r[n - 1] = 0;
    for (int i = n - 2; i >= 0; i --)
        if (s[i] == ')') r[i] = 0; else
        if (s[i] == '(')
        {
            int cur = i + 1;
            r[i] = r[cur];
            cur += r[cur];
            if (s[cur] == ')') r[i] += 2 + r[cur + 1]; else r[i] = 0;
        }


    for (int i = 0; i < n; i ++)
        if (r[i] > best) best = r[i];
    int mx = 0;
    for (int i = 0; i < n; i ++)
        if (r[i] == best) mx ++;

    if (best != 0) printf("%d %d\n", best, mx); else printf("0 1\n");

    return 0;
}