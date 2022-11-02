#include <bits/stdc++.h>

using namespace std;

int ans[1234567];

int main() {
    int n;
    scanf("%d", &n);
    int ac = 0;
    for (int i = 2; i <= n; i++) {
        bool ip = true;
        for (int j = 2; j * j <= i; j++) if (i % j == 0) {
            ip = false;
            break;
        }
        if (!ip) continue;
        for (int k = i; k <= n; k *= i) {
            ans[ac++] = k;
        }
    }
    printf("%d\n", ac);
    sort(ans, ans + ac);
    for (int i = 0; i < ac; i++) {
        if (i > 0) putchar(' ');
        printf("%d", ans[i]);
    }   
    puts("");
}