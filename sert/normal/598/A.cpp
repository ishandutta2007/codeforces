#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, st, t, sum;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        sum = (n * (n + 1)) / 2;
        st = 1;
        while (st * 2 <= n)
            st *= 2;
        sum -= 2 * (st * 2 - 1);
        cout << sum << "\n";
    }

    return 0;
}