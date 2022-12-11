#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[1000000];
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--) {
        m -= a[i];
        if (m <= 0) {
            cout << n - i;
            return 0;
        }
    }

    return 0;
}