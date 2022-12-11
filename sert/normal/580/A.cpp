#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

ll a[N], k, ans, n, kol;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = a[n - 1] - 1;
    kol = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= a[i - 1])
            kol++;
        else {
            ans = max(ans, kol);
            kol = 1;

        }
    }
    cout << ans;
    return 0;
}