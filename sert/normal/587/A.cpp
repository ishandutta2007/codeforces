#include <bits/stdc++.h>

using namespace std;

typedef int ll;
const int N = 2e6 + 7;

ll a[N];
ll n, m, t, k, ans;
string s;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        a[k]++;
    }

    for (int i = 0; i <= 1020000; i++) {
        if (a[i] % 2 == 1)
            ans++;
        a[i + 1] += a[i] / 2;
    }

    printf("%d\n", ans);

    return 0;
}