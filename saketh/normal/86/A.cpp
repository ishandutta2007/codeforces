#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nines[11];

int ndig(int val) {
    if (val == 0) return 0;
    return 1 + ndig(val / 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (int i = 1; i <= 10; i++)
        nines[i] = 10 * nines[i-1] + 9;

    int L, R;
    cin >> L >> R;


    ll ans = 0;

    for (int d = 1; d <= 10; d++) {
        ll best = nines[d] / 2;

        if (L <= best && best <= R) {
            ans = max(ans, best * (nines[d] - best));
        }
    }

    ans = max(ans, L * (nines[ndig(L)] - L));
    ans = max(ans, R * (nines[ndig(R)] - R));

    cout << ans << "\n";
}