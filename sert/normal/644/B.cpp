#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 34;

int n, k;
ll st, d;
ll a[N], len;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    /*for (int i = 0; i < 50; i++)
        for (int j = 0; j < 40; j++)
            cout << 50 + i << " " << 40 + j << "\n";
    return 0;*/
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%I64d%I64d", &st, &d);
        if (a + len - upper_bound(a, a + len, st) > k)
            printf("-1 ");
        else {
            if (len == 0) a[len] = st + d;
            else a[len] = max(a[len - 1], st) + d;
            printf("%I64d ", a[len++]);
        }
    }

    return 0;
}