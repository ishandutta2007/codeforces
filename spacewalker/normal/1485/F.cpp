#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

struct RiverBoi {
    map<ll, ll> cons;
    ll water; // the true keys are cons + water
    ll totalEntries;
    RiverBoi() : water(0), totalEntries(0) {}
    void shift(ll d) { water += d; }
    void clearEntry(ll d) {
        totalEntries = (totalEntries + MOD - cons[d-water]) % MOD;
        cons[d - water] = 0;
    }
    void addEntry(ll d, ll wt) {
        totalEntries = (totalEntries + wt) % MOD;
        cons[d - water] = (cons[d - water] + wt) % MOD;
    }
};

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<ll> arr(n);
        for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
        RiverBoi bryce;
        bryce.addEntry(arr[0], 1);
        for (int i = 1; i < n; ++i) {
            ll toAdd = bryce.totalEntries;
//            printf("adding %lld entires on %d\n", toAdd, i);
            bryce.shift(arr[i]);
            bryce.clearEntry(arr[i]);
            bryce.addEntry(arr[i], toAdd);
        }
        printf("%lld\n", bryce.totalEntries);
    }
}