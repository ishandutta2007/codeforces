#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int A = 26;

int solve(vector<int> cnt, int k, int need) {
    for (int i = 0; i < k; ++i) {
        int have = need;
        if (have % 2) {
            bool ok = false;
            for (int j = 0; j < A; ++j) {
                if (cnt[j] % 2) {
                    ok = true;
                    --have;
                    --cnt[j];
                    break;
                }
            }
            if (!ok) {
                for (int j = 0; j < A; ++j) {
                    if (cnt[j]) {
                        ok = true;
                        --have;
                        --cnt[j];
                        break;
                    }
                }
                if (!ok) {
                    return false;
                }
            }
        }
        for (int j = 0; j < A; ++j) {
            while (cnt[j] >= 2 && have) {
                have -= 2;
                cnt[j] -= 2;
            }
        }
        if (have > 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(A, 0);
    for (auto i : s) {
        cnt[i - 'a']++;
    }
    int L = 0, R = n + 1;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (solve(cnt, k, M)) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << L << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}