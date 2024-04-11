#include <bits/stdc++.h>
using namespace std;

#define N 20

int n, m;
char s[N][N], t[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%s", s[i]);
    for (int i = 0; i < m; i ++) scanf("%s", t[i]);
    int q;
    scanf("%d", &q);
    while (q --) {
        int x;
        scanf("%d", &x); x --;
        printf("%s%s\n", s[x%n], t[x%m]);
    }

    return 0;
}