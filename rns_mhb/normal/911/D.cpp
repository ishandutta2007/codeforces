#include <bits/stdc++.h>
using namespace std;
#define N 1505

int n, a[N], ans;
char s[][10] = {"even", "odd"};

int main() {
    scanf("%d", &n);
    int m, l, r;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) if (a[i] > a[j]) ans ^= 1;
    for (scanf("%d", &m); m --; ) {
        scanf("%d %d", &l, &r);
        r = r - l + 1 >> 1;
        if (r & 1) ans ^= 1;
        puts(s[ans]);
    }
}