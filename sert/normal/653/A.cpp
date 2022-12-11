#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

ll a[N];
int n, m, k, x, y;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 2] <= 2) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}