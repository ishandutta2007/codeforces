#include <bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e5 + 50, S = 100;

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;


int n, a[N];
unordered_map<int, int> mp;
int cnt[N * 2];
int xs[N], ssz = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int mxval = 0;
    rep(i, 0, n) cin >> a[i], mxval = max(mxval, a[i]);
    int res = 0;
    rep(i, 0, n) {
        ssz = 0;
        for (int j = i + 1; j < min(n, i + mxval / S + 1); j++) {
            if((a[j] - a[i]) % (j - i) == 0) {
                xs[ssz++] = (a[j] - a[i]) / (j - i) + N;
            }
        }
        rep(j, 0, ssz) res = max(res, 1 + (++cnt[xs[j]]));
        rep(j, 0, ssz) cnt[xs[j]] = 0;
    }

    rep(rv, 0, 2) {
        if(rv) {
            reverse(a, a + n);
        }

        rep(d, 0, S) {
            mp.clear();
            rep(i, 0, n) mp[a[i] - i * d]++;
            for (const auto &p : mp) res = max(res, p.second);
        }
    }
    cout << n - res << '\n';

}