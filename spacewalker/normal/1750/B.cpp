
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<ll> totals(2, 0);
        totals[s[0] - '0']++;
        vector<ll> runs{1};
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i-1]) runs.push_back(1);
            else runs.back()++;

            totals[s[i] - '0']++;
        }
        ll ans = totals[0] * totals[1];
        for (ll v : runs) ans = max(ans, v * v);
        printf("%lld\n", ans);
    }
}