#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define MAXN 100500

char s[MAXN];
char st[MAXN];
int cnt = 0;

int
main()
{
    scanf(" %s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        if (cnt == 0 || st[cnt - 1] != s[i])
        {
            st[cnt++] = s[i];
        }
        else
        {
            --cnt;
        }
    }
    if (cnt == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}