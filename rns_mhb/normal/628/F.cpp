#include <bits/stdc++.h>
using namespace std;

#define N 10005
#define K 5

typedef pair<int, int> pii;
int n, b, q;
pii a[N];

int main() {
    
    scanf("%d %d %d", &n, &b, &q);
    a[0] = pii(0, 0);
    for (int i = 1; i <= q; i ++) scanf("%d %d", &a[i].first, &a[i].second);
    a[++q] = pii(b, n);
    sort(a, a + q + 1);
    for (int i = 1; i <= q; i ++) if (a[i].second < a[i-1].second) {
        printf("unfair\n");
        return 0;
    }
    for (int mask = 0; mask < (1 << K); mask ++) {
        int can = 0;
        for (int i = 1; i <= q; i ++) {
            int s = 0;
            for (int j = a[i-1].first + 1; j <= a[i].first; j ++) {
                if ((mask >> (j % 5)) & 1) s ++;
            }
            can += min(s, a[i].second - a[i-1].second);
        }
        if (can < n / 5 * __builtin_popcount(mask)) {
            printf("unfair\n");
            return 0;
        }
    }
    printf("fair\n");
    return 0;
}