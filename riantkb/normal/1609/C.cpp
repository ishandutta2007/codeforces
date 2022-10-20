#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<bool> isprime(1000010, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i * i < 1000010; ++i) {
        if (!isprime[i]) continue;
        for (int j = i * i; j < 1000010; j += i) {
            isprime[j] = false;
        }
    }


    int T;
    // T = 1;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> lc(n), rc(n);
        for (int i = 0; i < n; ++i) {
            if (i >= e && a[i - e] == 1) {
                lc[i] = lc[i - e] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i + e < n && a[i + e] == 1) {
                rc[i] = rc[i + e] + 1;
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (isprime[a[i]]) {
                ans += (lc[i] + 1) * (long long)(rc[i] + 1) - 1;
            }
        }
        cout << ans << '\n';

    }
    return 0;
}