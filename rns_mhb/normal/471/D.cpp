#include <bits/stdc++.h>
using namespace std;

#define N 200010

int n, w, a[N], b[N], txt[N], pat[N], h[N], ans;

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 0; i < w; i ++) scanf("%d", &b[i]);
    for (int i = 1; i < n; i ++) txt[i] = a[i] - a[i - 1];
    for (int i = 1; i < w; i ++) pat[i] = b[i] - b[i - 1];
    if (w == 1) {
        printf("%d", n);
        return 0;
    }
    int k = 0;
    for (int i = 2; i < w; i ++) {
        while (pat[k + 1] != pat[i] && k) k = h[k];
        if (pat[i] == pat[k + 1]) h[i] = ++ k;
    }
    k = 0;
    for (int i = 1; i < n; i ++) {
        while (k && pat[k + 1] != txt[i]) k = h[k];
        if (pat[k + 1] == txt[i]) k ++;
        if (k == w - 1) {
            ans ++;
            k = h[k];
        }
    }
    printf("%d", ans);
}