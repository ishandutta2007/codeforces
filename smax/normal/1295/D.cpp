#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        long long a, m;
        cin >> a >> m;

        m /= __gcd(a, m);
        long long ret = m;
        for (long long i=2; i*i<=m; i++)
            if (m % i == 0) {
                while (m % i == 0)
                    m /= i;
                ret -= ret / i;
            }
        if (m > 1)
            ret -= ret / m;

        cout << ret << "\n";
    }

    return 0;
}