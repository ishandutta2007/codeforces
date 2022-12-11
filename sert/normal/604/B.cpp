#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[1000000], ans;
int main() {
   //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    m = min(n, m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= n * 2 - m * 2; i--)
        ans = max(ans, a[i]);
    for (int i = 0; i < n - m; i++)
        ans = max(ans, a[i] + a[n * 2 - m * 2 - i - 1]);
    cout << ans;

    return 0;
}