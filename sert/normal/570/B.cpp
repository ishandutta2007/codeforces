#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll n, m;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    cout << (m <= n / 2 ? m + 1 : m - 1);
    return 0;
}