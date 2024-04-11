#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 3e6 + 7;
const long double EPS = 1e-12;

ll n, a[N], p[N], ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", i + a);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[n - i - 1];

    while (n) {
        ans += p[n];
        n /= 4;
    }

    cout << ans;

    return 0;
}