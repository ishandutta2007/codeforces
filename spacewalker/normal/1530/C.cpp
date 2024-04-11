#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll score(vector<ll> &rounds) { // rounds is sorted
    int n = rounds.size();
    ll ans = 0;
    for (int i = 0; i < n - n / 4; ++i) {
        ans += rounds[n - 1 - i];
    }
    return ans;
}

int solve() {
    int n; scanf("%d", &n);
    vector<ll> me(n), ilya(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &me[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &ilya[i]);
    int lo = 0, hi = 3 * n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        vector<ll> newMe = me, newIlya = ilya;
        for (int k = 0; k < mid; ++k) {
            newMe.push_back(100);
            newIlya.push_back(0);
        }
        sort(begin(newMe), end(newMe));
        sort(begin(newIlya), end(newIlya));
        if (score(newMe) >= score(newIlya)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%d\n", solve());
}