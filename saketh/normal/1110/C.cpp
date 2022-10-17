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
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    unordered_map<int, int> cache;

    int magic[26] = {
        -1,
        -1,
        1,
        1,
        5,
        1,
        21,
        1,
        85,
        73,
        341,
        89,
        1365,
        1,
        5461,
        4681,
        21845,
        1,
        87381,
        1,
        349525,
        299593,
        1398101,
        178481,
        5592405,
        1082401
    };
    for (int e = 2; e <= 25; e++) {
        cache[(1 << e) - 1] = magic[e];
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int a;
        cin >> a;
        if (cache.count(a)) {
            cout << cache[a] << "\n";
            continue;
        }

        int pow2 = 1;
        while (pow2 <= a) {
            pow2 *= 2;
        }
        pow2 -= 1;

        if (pow2 > a) {
            cout << (cache[a] = pow2) << "\n";
        } else {
            assert(false);
        }
    }

    return 0;
}