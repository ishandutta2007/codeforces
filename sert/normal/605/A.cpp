#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
int n, a[N], b[N], x, p, kol, ans;
int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x - 1] = i;
    }
    a[n] = -2;
    p = 0;
    while (p < n) {
        kol = 1;
        while (a[p] < a[p + 1]) {
            p++;
            kol++;
        }
        ans = max(ans, kol);
        p++;
    }
    cout << n - ans;
    return 0;
}