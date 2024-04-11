#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair
// #define int ll

#define debug(x) cout << #x << " = " << x << endl;

const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);

// const int MEM_SIZE = 5e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("cowboys");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

const int mod = 998244353;

vector<pii> remove_inside(const vector<pii> &v) {
    int mx = -INF;
    vector<pii> ans;
    for (auto &[l, r] : v) {
        if (cmax(mx, r)) {
            ans.pb({l, r});
        }
    }
    return ans;
}

vector<pii> remove_outside(const vector<pii> &v) {
    vector<pii> ans;
    for (int i = len(v) - 1; i > -1; --i) {
        if (len(ans) && v[i].second >= ans.back().second) {
            continue;
        }
        ans.pb(v[i]);
    }
    reverse(all(ans));
    return ans;
}

int solve(int n, const vector<pair<int, int>> &segs0, const vector<pair<int, int>> &segs1) {
    int it0 = 0, it1 = 0;
    vector<int> dp(n + 2, 0);
    dp[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        while (it0 < len(segs0) && segs0[it0].second < i) {
            ++it0;
        }
        while (it1 < len(segs1) && segs1[it1].second < i) {
            ++it1;
        }
        int l = 0;
        if (it0 > 0) {
            l = segs0[it0 - 1].first + 1;
        }
        // for (int j = l; j < i; ++j) {
        //     dp[i] += dp[j];
        //     if (dp[i] >= mod) {
        //         dp[i] -= mod;
        //     }
        // }
        dp[i] = dp[i - 1];
        if (l > 0) {
            dp[i] -= dp[l - 1];
            if (dp[i] < 0) {
                dp[i] += mod;
            }
        }
        if (it1 < len(segs1) && segs1[it1].first < i) {
            dp[i] = 0;
        }
        dp[i] += dp[i - 1];
        if (dp[i] >= mod) {
            dp[i] -= mod;
        }
    }
    return (dp.back() - dp[n] + mod) % mod;
}

void run() {
    int n, m, k;
    cin >> n >> k >> m;
    vector<array<int, 3>> segs(m);
    for (auto &[l, r, x] : segs) {
        cin >> l >> r >> x;
        --l;
    }
    sort(all(segs), [](const array<int, 3> &a, const array<int, 3> &b) {
        if (a[0] != b[0]) {
            return a < b;
        }
        return a > b;
    });
    ll ans = 1;
    vector<pii> segs0, segs1;
    for (int i = 0; i < k; ++i) {
        for (auto &[l, r, x] : segs) {
            if (x & (1 << i)) {
                segs1.pb({l, r});
            } else {
                segs0.pb({l, r});
            }
        }
        segs0 = remove_outside(segs0);
        segs1 = remove_inside(segs1);
        ans *= solve(n, segs0, segs1);
        ans %= mod;
        segs0.clear();
        segs1.clear();
    }
    cout << ans << endl;
}