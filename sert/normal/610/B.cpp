#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 34;
long long a[N], mn = 1e9 + 34, ans, n, kol;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        a[i + n] = a[i];
    }
    a[n * 2] = mn;
    for (int i = 0; i <= n * 2; i++)
        if (a[i] > mn)
            kol++;
        else {
            ans = max(ans, kol);
            kol = 0;
        }
    cout << mn * n + ans;
    return 0;
}