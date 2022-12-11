#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 340;
const ll INF = 1e9;
const ll md = 1e9 + 7;
const ll o720 = 301388891;

int n, k;

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> k;
    if (k > (n - 1) / 2) {
        cout << -1;
        return 0;
    }

    cout << k * n << "\n";

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++)
            cout << j + 1 << " " << (j + i) % n + 1 << "\n";
    }

    return 0;
}