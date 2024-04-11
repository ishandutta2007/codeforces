#include <bits/stdc++.h>
using namespace std;
#define N 15

char f[N], l[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%s %s", f, l);
    int lenf = strlen(f), lenl = strlen(l), i;
    for (i = 1; i < lenf; i ++) {
        if (f[i] >= l[0]) break;
    }
    f[i] = 0;
    printf("%s%c\n", f, l[0]);

    return 0;
}