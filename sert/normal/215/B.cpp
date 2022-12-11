#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8000;
const ll md = 1e9 + 7;

int n, a[N];
long double aa, bb, r1, p2, p1;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n; for (int i = 0; i < n; i++) cin >> a[i]; sort(a, a + n); r1 = a[n - 1];
    cin >> n; for (int i = 0; i < n; i++) cin >> a[i]; sort(a, a + n); p1 = a[n - 1];
    cin >> n; for (int i = 0; i < n; i++) cin >> a[i]; sort(a, a + n); p2 = a[0];
    cin >> aa >> bb;
    cout.precision(10);
    cout << fixed << sqrtl((bb * r1 * r1 * p1) / (aa * p2 + bb * p1));


    return 0;
}