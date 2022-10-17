#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int last = 0;
    umap<int, int> loc;
    vector<umap<int, int>> fam;

    auto get_loc = [&](int i) {
        auto it = loc.find(i);
        return (it != loc.end()) ? it->second : -1;
    };

    auto merge = [&](int src, int dst, int sv, int dv, int x) {
        int e1 = fam[dst][dv];
        int e4 = fam[src][sv];
        for (auto &[k, v] : fam[src]) {
            loc[k] = dst;
            fam[dst][k] = e1 ^ x ^ v ^ e4;
        }
        fam[src].clear();
    };

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t, l, r, x;
        cin >> t;
        if (t == 1) {
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
            if (l > r) swap(l, r);

            // tells us that p[l-1] ^ p[r] is equal to x
            int f1 = get_loc(l-1);
            int f2 = get_loc(r);

            if (f1 != -1 && f1 == f2) {
                // already know, don't care
                continue;
            }
            if (f1 == -1 && f2 == -1) {
                loc[l-1] = fam.size();
                loc[r] = fam.size();
                fam.push_back(umap<int, int>());
                fam.back()[l-1] = 0;
                fam.back()[r] = x;
            } else if (f1 == -1) {
                loc[l-1] = f2;
                fam[f2][l-1] = fam[f2][r] ^ x;
            } else if (f2 == -1) {
                loc[r] = f1;
                fam[f1][r] = fam[f1][l-1] ^ x;
            } else {
                if (fam[f1].size() < fam[f2].size()) {
                    merge(f1, f2, l-1, r, x);
                } else {
                    merge(f2, f1, r, l-1, x);
                }
            }
        } else {
            cin >> l >> r;
            l ^= last;
            r ^= last;
            if (l > r) swap(l, r);

            int f1 = get_loc(l-1);
            int f2 = get_loc(r);
            if (f1 != -1 && f1 == f2) {

                int res = fam[f1][r] ^ fam[f1][l-1];
                cout << res << "\n";
                last = res;
            } else {
                cout << -1 << "\n";
                last = 1;
            }
        }
    }

    return 0;
}