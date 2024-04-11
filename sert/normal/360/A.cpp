#include <string>
#include <fstream>;
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int N = 5034;

long long a[N], b[N];
long long n, m, t[N], l[N], r[N], x[N], mx;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) a[i] = 1e9;
    for (int i = 0; i < m; i++) {
        cin >> t[i] >> l[i] >> r[i] >> x[i];
        if (t[i] == 1)
            for (int j = l[i]; j <= r[i]; j++)
                b[j] += x[i];
        else
            for (int j = l[i]; j <= r[i]; j++)
                a[j] = min(a[j], x[i] - b[j]);
    }
    for (int i = 0; i <= n; i++) b[i] = 0;
    for (int i = 0; i < m; i++)
        if (t[i] == 1)
            for (int j = l[i]; j <= r[i]; j++)
                b[j] += x[i];
        else {
            mx = -1e9;
            for (int j = l[i]; j <= r[i]; j++)
                mx = max(mx, a[j] + b[j]);
            if (mx != x[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << a[i + 1] << " ";
}