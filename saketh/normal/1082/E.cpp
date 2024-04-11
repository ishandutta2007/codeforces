#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class K> struct sp64_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const K& x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(hash<K>()(x) + FIXED_RANDOM);
    }
};

template<class K, class V> using umap = gp_hash_table<K, V, sp64_hash<K>>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C;
    cin >> N >> C;

    vi a(N), pref(N);
    umap<int, vi> apps;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (i) pref[i] = pref[i-1];
        if (a[i] == C) pref[i]++;
        else apps[a[i]].push_back(i);
    }

    int ans = pref.back(), maxd = 0;

    for (auto& [v, locs] : apps) {
        int best = 0;
        for (int i = 0; i < locs.size(); i++) {
            best = min(best, i - pref[locs[i]]);
            maxd = max(maxd, i + 1 - pref[locs[i]] - best);
        }
        maxd = max(maxd, best);
    }

    cout << ans + maxd << endl;

    return 0;
}