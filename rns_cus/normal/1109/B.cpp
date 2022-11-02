#include <bits/stdc++.h>
using namespace std;

#define N 5555

int n;
char s[N], t[N];

int main() {
    scanf("%s", s);
    n = strlen(s);
    bool fg = 0;
    for (int i = 1; i < n / 2; i ++)
        if (s[i] != s[i-1]) fg = 1;
    if (!fg) puts("Impossible");
    else {
        if (n % 2 == 0) {
            for (int i = 1; i < n; i ++) {
                for (int j = i; j < n; j ++) t[j-i] = s[j];
                for (int j = 0; j < i; j ++) t[n-i+j] = s[j];
                if (strcmp(s, t)) {
                    bool p = 1;
                    for (int i = 0; i < n; i ++) {
                        if (t[i] != t[n-1-i]) {
                            p = 0;
                            break;
                        }
                    }
                    if (p) {
                        fg = 0;
                        break;
                    }
                }
            }
        }
        if (fg) puts("2");
        else puts("1");
    }

    return 0;
}