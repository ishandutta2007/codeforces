#include <bits/stdc++.h>
using namespace std;
const int N = 190;
typedef long long ll;
typedef long double ld;

ld a[N][N], tmp;
int n, t, ans = 0;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> t;
    a[0][0] = t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (a[i][j] + 1e-8 > 1) {
                ans++;
                tmp = (a[i][j] - 1.0) * 0.5;
                a[i + 1][j] += tmp;
                a[i + 1][j + 1] += tmp;
            }
        }
    }
    cout << ans;
    return 0;
}