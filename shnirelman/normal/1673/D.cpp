#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 4e4 + 13;
const int K = 513;
const int M = 1e9 + 7;
const int LOGN = 20;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

void solve() {
    int b, q, y;
    cin >> b >> q >> y;

    int c, r, z;
    cin >> c >> r >> z;

    if(r % q != 0 || c < b || c + (z - 1) * 1ll * r > b + (y - 1) * 1ll * q || (c - b) % q != 0) {
        cout << 0 << endl;
    } else if(c - r < b || c + (z - 1) * 1ll * r + r > b + (y - 1) * 1ll * q) {
        cout << -1 << endl;
    } else {
        int ans = 0;
        for(int i = 1; i * i <= r; i++) {
            for(int p = i, _ = 0; _ < 1 + (i * i != r); _++, p = r / i) {
//                if(__gcd(r / p, r / q) != 1)
                if(p * 1ll * q / __gcd(p, q) != r)
                    continue;

//                cout << "p = " << p << endl;

                ans = sum(ans, (r / p) * 1ll * (r / p) % M);

            }
        }

        cout << ans << endl;
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}