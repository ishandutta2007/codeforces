#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
const int qu = 1e9 + 34;
int n, k, a[N], q;
char ss[12];
int main() {
    //freopen("a.in", "r", stdin);

    scanf("%d %d\n", &n, &k);
    for (int i = 0; i <= n; i++) {
        gets(ss);
        if (ss[0] == '?') {
            a[i] = qu;
            q++;
        } else {
            sscanf(ss, "%d", a + i);
        }
    }
    for (int i = 0; i <= n; i++)
        cerr << a[i] << "\n";

    if (k == 0) {
        if (((n + 1 - q) % 2 && a[0] == qu) || a[0] == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        return 0;
    }

    if (q > 0) {
        if (n % 2) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        return 0;
    }

    int mk = abs(k);

    int ost = 0;
    for (int i = 0; i <= n; i++) {
        ost /= mk;
        if (i % 2 && k < 0)
            ost -= a[i];
        else
            ost += a[i];

        if (ost % mk) {
            printf("No\n");
            return 0;
        }
    }

    if (ost)
        printf("No\n");
    else
        printf("Yes\n");

    return 0;
}