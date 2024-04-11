

#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, k, cur[N], vis[N];
char s[N];

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 0, cnt = 0; k < n; i ++) {
        if (s[i] == ')') {
            vis[i] = vis[cur[--cnt]] = 1;
            k += 2;
        }
        else cur[cnt++] = i;
    }
    for (int i = 0; i < n; i ++) if (!vis[i]) putchar(s[i]); puts("");

    return 0;
}