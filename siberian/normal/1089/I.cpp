#include <bits/stdc++.h>

#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define px pair<db, db>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define input(a) for (auto& el : a) cin >> el;
#define output(a) cout << '!'; for (auto& el : a) cout << el << ' '; cout << '\n'; cout.flush();
#define sz(el) int(el.size())
#define sq(a) ((a) * (a))
#define xll __int128
#define xmin(a,b) a = min(a, b)
#define xmax(a,b) a = max(a, b)
#define sun(a) sort(all(a)); a.resize(unique(all(a)) - a.begin());

using namespace std;

template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
    return (out << p.f << ' ' << p.s << endl);
}

const int INF = 1000000017;
const ll LLINF = 1000000000000000017LL;
const ld inf = 1.0 / 0.0;
const ld eps = 1e-10;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;

//mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

//uniform_int_distribution<int> uid(l, r); [l, r]
//int x = uid(rng);

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tret;

/// *find_by_order - val by index, order_of_key - # less than x
*/

const int N = 405;
ll f[N] = {};
ll dp[N][N] = {};
ll inv[N][N] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, p;
    cin >> q >> p;

    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % p;
    }
    for (int n = 1; n < N; ++n) {
        dp[n][1] = f[n];
        for (int k = 2; k <= n; ++k) {
            for (int m = 0; m <= n - k; ++m) {
                dp[n][k] += f[m + 1] * dp[n - m - 1][k - 1];
                dp[n][k] %= p;
            }
        }
    }

    for (int n = 1; n < N; ++n) {
        for (int k = 1; k <= n; ++k) {
            ll cur = 0;
            for (int m = 1; m < n; ++m) {
                cur += dp[n][m] * inv[m][k];
                cur %= p;
            }
            inv[n][k] = ((n == k) - cur + p);
            if (inv[n][k] >= p) {
                inv[n][k] -= p;
            }
        }
    }

    while (q--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << 2 << '\n';
        } else {
            cout << ((-inv[n][1] + 2 * (n % 2 == 0 ? -1 : 1)) % p + p) % p << '\n';
        }
    }
    return 0;
}