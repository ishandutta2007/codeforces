#include <bits/stdc++.h>
using namespace std;

int fact[250001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    fact[0] = 1;
    for (int i=1; i<=n; i++)
        fact[i] = (long long) fact[i-1] * i % m;

    int ret = 0;
    for (int len=1; len<=n; len++) {
        ret += (long long) (n - len + 1) * fact[len] % m * fact[n-len+1] % m;
        ret %= m;
    }

    cout << ret << "\n";

    return 0;
}