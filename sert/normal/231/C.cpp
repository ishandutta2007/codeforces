#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;
int a[N], mx = -1, ch = -1;
ll p[N];
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];
    long long l, m, r, sum;
    for (int i = 0; i < n; i++) {
        l = 0;
        r = i + 1;
        while (r - l > 1) {
            m = (l + r) / 2;
            sum = m * a[i] - p[i] + p[i - m];
            if (sum <= k)
                l = m;
            else
                r = m;
        }
        if (l + 1 > mx) {
            mx = l + 1;
            ch = a[i];
        }
    }

    printf("%d %d\n", mx, ch);


    return 0;
}