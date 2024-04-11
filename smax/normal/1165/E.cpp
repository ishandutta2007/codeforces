#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long a[200000], b[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] *= (long long) (i + 1) * (n - i);
    }
    for (int i=0; i<n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n, greater<int>());

    int ret = 0;
    for (int i=0; i<n; i++)
        ret = (ret + a[i] % MOD * b[i] % MOD) % MOD;

    cout << ret << "\n";

    return 0;
}