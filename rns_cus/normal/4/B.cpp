#include <bits/stdc++.h>
using namespace std;

#define N 111
int d, s;
int a[N], b[N], c[N];

int main() {
    scanf("%d %d", &d, &s);
    int tot = 0;
    for (int i = 0; i < d; i ++) {
        scanf("%d %d", &a[i], &b[i]);
        s -= a[i], b[i] -= a[i];
        tot += b[i];
    }
    if (s < 0 || s > tot) puts("NO");
    else {
        puts("YES");
        for (int i = 0; i < d; i ++) {
            c[i] = a[i];
            if (s > b[i]) c[i] += b[i], s -= b[i];
            else {
                c[i] += s; s = 0;
            }
            printf("%d ", c[i]);
        }
    }

    return 0;
}