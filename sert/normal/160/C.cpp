#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 34;
const ll INF = 1e9;

ll a[N], k, n, p, kol, kl;

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> k;
    k--;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    p = k / n;
    cout << a[p] << " ";
    kol = upper_bound(a, a + n, a[p]) - lower_bound(a, a + n, a[p]);
    kl = a + p - lower_bound(a, a + n, a[p]);
    cout << a[(kl * n + k % n) / kol];
    return 0;
}