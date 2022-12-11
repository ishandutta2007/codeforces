#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const long double EPS = 1e-12;

ll a, b, c, n, m, d[N], ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        d[a] -= c;
        d[b] += c;
    }
    for (int i = 0; i < n; i++)
        ans += abs(d[i]);
    cout << ans / 2;

    return 0;
}