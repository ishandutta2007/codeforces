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

#define int ll

const int C = 1e6 + 10;

bool prime[C];

void precalc() {
    fill(prime, prime + C, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < C; ++i) {
        if (prime[i]) {
            for (int j = i + i; j < C; j += i) {
                prime[j] = false;        
            }
        }
    }
}

ll calc(const vector<int>& a) {
    ll ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (!a[i]) continue;
        int cntL = 0;
        for (int j = i - 1; j >= 0 && a[j] == 0; --j) {
            ++cntL;
        }
        int cntR = 0;
        for (int j = i + 1; j < (int)a.size() && a[j] == 0; ++j) {
            ++cntR;
        }
        ans += (ll)(cntL + 1) * (cntR + 1) - 1;
    }
    return ans;
}

void solve() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> have(e);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (prime[x]) {
            have[i % e].push_back(1);
        } else if (x == 1) {
            have[i % e].push_back(0);
        } else {
            ans += calc(have[i % e]);
            have[i % e].clear();
        }
    }

    for (int i = 0; i < e; ++i) {
        ans += calc(have[i]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    precalc();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}