#include <bits/stdc++.h>
using namespace std;

#define N 1000005

int n, p;
char s[N], t[N];
int b;

int main() {
    gets(s);
    n = strlen(s);
    p = n;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '.') p = i;
    }
    b = -(n - 1 - min(n - 1, p));
    n = 0;
    for (int i = 0; s[i]; i ++) if (s[i] != '.') t[n++] = s[i];
    int j = -1;
    for (int i = 0; i < n; i ++) {
        if (t[i] != '0') {
            j = i;
            break;
        }
    }
    if (j < 0) return puts("0"), 0;
    b += n - 1 - j;
    int k;
    for (int i = n - 1; i >= j; i --) {
        if (t[i] != '0') {
            k = i;
            break;
        }
    }
    printf("%c", t[j]);
    if (k != j) {
        printf(".");
        for (int i = j + 1; i <= k; i ++) printf("%c", t[i]);
    }
    if (b) {
        printf("E%d\n", b);
    }
    return 0;
}