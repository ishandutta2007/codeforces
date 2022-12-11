#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k;
ll mx, b[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mx = a[n - 1] - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= mx)
            b[i] = mx + 1 - a[i];
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    return 0;
}