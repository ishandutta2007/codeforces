#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, m;
char s[N], t[N];

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s %s", s, t);
    int k;
    for (k = 0; k < n; k ++) if (s[k] == '*') break;
    if (k == n) {
        if (m != n) puts("No");
        else {
            for (k = 0; k < m; k ++) if (s[k] != t[k]) break;
            puts(k < m ? "No" : "Yes");
        }
    }
    else {
        bool fg = 1;
        for (int i = 0; i < k; i ++) if (s[i] != t[i]) fg = 0;
        for (int i = k + 1; i < n; i ++) if (s[i] != t[i+m-n]) fg = 0;
        if (n > m + 1) fg = 0;
        puts(fg ? "Yes" : "No");
    }

    return 0;
}