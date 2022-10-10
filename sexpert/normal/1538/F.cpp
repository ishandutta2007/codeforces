#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p10[12];

ll solve(string s) {
    int d = s.size();
    ll ans = 0;
    for(int i = 0; i < d; i++) {
        ll tot = 0;
        int rem = d - i - 1;
        for(int j = 0; j < rem; j++)
            tot += p10[j];
        ans += tot * (s[i] - '0');
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p10[0] = 1;
    for(ll i = 1; i < 12; i++)
        p10[i] = 10LL * p10[i - 1];

    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        cout << solve(to_string(r)) - solve(to_string(l)) + r - l << '\n';
    }
}