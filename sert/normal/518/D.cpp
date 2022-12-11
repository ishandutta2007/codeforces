#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

long double p, ans, a[2011][2011];
int n, t;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> p >> t;
    a[0][0] = 1.0;
    for (int tm = 1; tm <= t; tm++) {
        for (int num = 0; num <= n; num++) {
            if (num < n)
                a[tm][num] += a[tm - 1][num] * (1.0 - p);
            else
                a[tm][num] += a[tm - 1][num];
            if (num)
                a[tm][num] += a[tm - 1][num - 1] * p;
            //cout << a[tm][num] << " ";
        }
        //cout << "\n";
    }
    for (int i = 0; i <= n; i++)
        ans += a[t][i] * i;

    cout.precision(10);
    cout << fixed << ans;

    return 0;
}