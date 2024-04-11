#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll cur = 1, cf = 1;
    for(int i = 1; i <= n; i++) {
        cf = (cf * i) % MOD;
        if(i > 1)
            cur = (cur + cur) % MOD;
    }
    cout << (cf - cur + MOD) % MOD << '\n';
}