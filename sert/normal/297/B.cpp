#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int n, m, k, a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < m; i++) scanf("%d", b + i);
    n = max(n, m);
    sort(a, a + n);
    sort(b, b + n);

    for (int i = n - 1; i >= 0; i--)
    if (a[i] > b[i]) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}