#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll n, k, r = 1;
        cin >> n >> k;
        while(k--)
            r = (r * n) % MOD;
        cout << r << '\n';
    }
}