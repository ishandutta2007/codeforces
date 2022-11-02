#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, k;
char a[N], b[N];

int main() {
    scanf("%d %d", &n, &k); scanf("%s", a + 1);
    for (int i = 1; i <= k; i ++) b[i] = a[i];
    for (int i = k + 1; i <= n; i ++) b[i] = b[i-k];
    int x;
    for (x = 1; x <= n; x ++) if (a[x] != b[x]) break;
    if (x > n || b[x] > a[x]) {
        printf("%d\n", n);
        puts(b + 1);
    }
    else {
        int t = k;
        while (t && b[t] == '9') b[t] = '0', t --;
        assert(t);
        b[t] ++;
        for (int i = k + 1; i <= n; i ++) b[i] = b[i-k];
        printf("%d\n", n);
        puts(b + 1);
    }

    return 0;
}