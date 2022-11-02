#include <stdio.h>
#include <algorithm>
using namespace std;
int x[111111];

int main() {
//  freopen ("in.txt", "r", stdin);
    int n, i, j, k, a, b;
    scanf ("%d", &n);
    for (i=0; i<n; i++) scanf ("%d", x+i);
    sort (x, x+n);
    n = unique (x, x+n) - x;
    scanf ("%d %d", &a, &b);
    int ans = 0;
    while (a != b) {
        int m=a-1;
        for (i=0; i<n; i++) if (a-a%x[i] >= b) m=min(m, a-a%x[i]);
        a=m;
        ans++;
        while (n && a-a%x[n-1]<b) n--;
    }
    printf ("%d\n", ans);
}