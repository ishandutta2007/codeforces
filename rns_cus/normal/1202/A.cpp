#include <bits/stdc++.h>
using namespace std;

#define N 100100

char s[N], t[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s %s", s, t);
        int n = strlen(s), m = strlen(t);
        reverse(s, s + n), reverse(t, t + m);
        int x, y;
        for (y = 0; t[y] == '0'; y ++);
        for (x = y; s[x] == '0'; x ++);
        printf("%d\n", x - y);
    }

    return 0;
}