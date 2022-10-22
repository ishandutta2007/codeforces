#include <bits/stdc++.h>

using namespace std;

bool is(long long n, long long m) {
    if(m % 2 == 0) {
        long long k = n - m / 2;
        return k * 1ll * (k - 1) / 2 >= m / 2;
    } else {
        long long k = n - (m + 1) / 2;
        return k * 1ll * (k - 1) / 2 >= m / 2;

    }
}

void solve() {
    long long n;
    cin >> n;

    if(n == 1) {
        cout << 0 << endl;
        return;
    }

    long long l = 0, r = 2 * n + 1;
    while(r - l > 1) {
        long long m = (l * 1ll + r) / 2;

        if(is(n, m))
            l = m;
        else
            r = m;
    }

    cout << l << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}