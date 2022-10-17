#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K, A, B;

ll floor(ll val) {
    if (val % K == 0) return val;
    if (val >= 0) return val - (val % K);
    return val - (val % K) - K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> K >> A >> B;

    ll AF = floor(A), BF = floor(B);

    ll ans = (BF - AF) / K;
    if (AF == A) ans++;

    cout << ans << "\n";
}