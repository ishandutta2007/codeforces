#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;
    int ones = (1 << K) - 1;

    gp_hash_table<long long, int, custom_hash> ct;
    ct[0]++;
    int pref = 0;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int xc = x ^ ones;

        if (ct[pref ^ x] <= ct[pref ^ xc]) {
            ans += ct[pref ^ x];
            ct[pref ^ x]++;
            pref ^= x;
        } else {
            ans += ct[pref ^ xc];
            ct[pref ^ xc]++;
            pref ^= xc;
        }
    }

    ll total = N * 1ll * (N - 1) / 2 + N;
    cout << total - ans << endl;
    return 0;
}