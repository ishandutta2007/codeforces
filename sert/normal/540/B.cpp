#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll a[N];
ll n, k, p, x, y, m;
ll k1, k2, sum;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> k >> p >> x >> y;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = k; i < n; i++)
        a[i] = y;

    sort(a, a + n);
    for (int i = 0; i < n; i++)
        if (a[i] >= y) {
            p = i;
            break;
        }
    m = n / 2;
    if (p > m) {
        cout << -1;
        return 0;
    }

    k1 = min(m - p, n - k);
    k2 = n - k - k1;

    sum += k1 + k2 * y;

    if (sum > x) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < k1; i++) cout << "1 ";
    for (int i = 0; i < k2; i++) cout << y << " ";


    //return 0;
}