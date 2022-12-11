#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const long double EPS = 1e-12;

ll a[N], p[N], s[N], x, k, n, y = 1, ans = -1;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> k >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        y *= x;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] | a[i - 1];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] | a[n - i];
    for (int i = 0; i < n; i++)
        ans = max(ans, (p[i] | (y * a[i]) | s[n - i - 1]));
    cout << ans;

    return 0;
}