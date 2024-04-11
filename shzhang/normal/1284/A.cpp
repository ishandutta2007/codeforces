#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

int n, m;
char s[25][25];
char t[25][25];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", t[i]);
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int y;
        scanf("%d", &y);
        y--;
        printf("%s%s\n", s[y%n], t[y%m]);
    }
    return 0;
}