#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 41;
int a[N], n, m, cur, bst, l, r, t;
int main() {
    //freopen("a.in", "r", stdin);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    cur = 0;
    for (int i = 0; i < n; i++) {
        while (cur < n && (a[cur] == 1 || t < m)) {
            if (a[cur] == 0)
                t++;
            cur++;
        }
        if (cur - i > bst) {
            bst = cur - i;
            r = cur;
            l = i;
        }
        if (a[i] == 0)
            t--;
    }

    for (int i = l; i < r; i++)
        a[i] = 1;
    printf("%d\n", bst);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}