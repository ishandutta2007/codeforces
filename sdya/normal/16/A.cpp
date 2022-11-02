#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int n, m;
int color[200];
char s[300];

int main()
{
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        gets(s);
        int k = strlen(s);
        int a = s[0] - '0';
        int p = 0;
        for (int i = 0; i < k; i ++)
            if (s[i] == s[0]) p ++;
        if (p != k) color[i] = -1; else color[i] = a;
    }

    bool good = true;
    for (int i = 1; i <= n; i ++)
        if (color[i] == -1) good = false;
    for (int i = 2; i <= n; i ++)
        if (color[i] == color[i - 1])
            good = false;
    if (good) printf("YES\n"); else
        printf("NO\n");
    return 0;
}