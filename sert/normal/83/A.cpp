#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

ll a[N], k = 1, ans, n;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = a[n - 1] + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1])
            k++;
        else {
            ans += k * (k + 1) / 2;
            k = 1;
        }
    }
    cout << ans;
    return 0;
}