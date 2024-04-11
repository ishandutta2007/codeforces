#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e5 + 34;
const ld EPS = 1e-4;

int n, k, a[N], d[N], ans;
ld shit;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> shit;
    }
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i])
                d[i] = max(1 + d[j], d[i]);
        ans = max(ans, d[i]);
    }
    cout << n - ans;

    return 0;
}