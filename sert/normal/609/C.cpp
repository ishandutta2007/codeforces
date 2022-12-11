#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int n, x, a[N], mx = -N, mn = N, ans;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
        mx = max(x, mx);
        mn = min(x, mn);
    }

    while (mx - mn > 1) {
        a[mn]--;
        a[mx]--;
        a[mn + 1]++;
        a[mx - 1]++;
        while (a[mn] == 0) mn++;
        while (a[mx] == 0) mx--;
        ans++;
    }

    cout << ans;



    return 0;
}