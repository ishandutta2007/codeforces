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

const int N = 1e6 + 228;
const int LOG = 62;
int n;
ll a[N];
int ppc[N];
ll ans = 0;

int popcount(ll x) {
    return __builtin_popcountll(x);
}

int prefMax[N];
int prefMin[N];
int prefppc[N];
vector<int> pos[LOG];

void buildPref(int m, int r) {
    for (int i = 0; i < LOG; ++i) {
        pos[i].clear();
    }
    for (int i = m; i < r; ++i) {
        prefMax[i] = a[i];
        prefppc[i] = ppc[i];
        prefMin[i] = a[i];
        if (i != m) {
            if (prefMax[i - 1] > prefMax[i]) {
                prefMax[i] = prefMax[i - 1];
                prefppc[i] = prefppc[i - 1];
            }
            chkmin(prefMin[i], prefMin[i - 1]);
        }
        pos[prefppc[i]].push_back(i);
    }
}

int getCnt(int bit, int l, int r) {
    if (l >= r) return 0;
    return lower_bound(all(pos[bit]), r) - lower_bound(all(pos[bit]), l);
}

void relax(int l, int m, int r, int flag) {
    // min & max in left
    buildPref(m, r);
    {
        int j = m;
        pair<ll, int> valMin = {a[m - 1], ppc[m - 1]};
        pair<ll, int> valMax = {a[m - 1], ppc[m - 1]};
        for (int i = m - 1; i >= l; --i) {
            chkmin(valMin, mp(a[i], ppc[i]));
            chkmax(valMax, mp(a[i], ppc[i]));
            if (valMax.second != valMin.second) continue;
            for (; j < r; ++j) {
                int curMin = prefMin[j];
                int curMax = prefMax[j];
                if (!(valMin.first <= curMin - flag)) break;
                if (!(valMax.first >= curMax + 1)) break; 
            }
            ans += j - m;
        }
    }
    // min in left, max in right
    {
        pair<ll, int> valMin = {a[m - 1], ppc[m - 1]};
        pair<ll, int> valMax = {a[m - 1], ppc[m - 1]};
        int maxj = m;
        int minj = m;
        for (int i = m - 1; i >= l; --i) {
            chkmin(valMin, mp(a[i], ppc[i]));
            chkmax(valMax, mp(a[i], ppc[i]));
            for (; maxj < r; ++maxj) {
                int curMin = prefMin[maxj];
                if (!(valMin.first <= curMin - flag)) break;
            }
            for (; minj < r; ++minj) {
                int curMax = prefMax[minj];
                if (!(curMax >= valMax.first)) continue;
                break;
            }

            ans += getCnt(valMin.second, minj, maxj);
        }
    }
}

void solve(int l, int r) {
    if (l == r - 1) {
        ++ans;
    } else {
        int m = (l + r) / 2;
        solve(l, m);
        solve(m, r);
        relax(l, m, r, 0);
        reverse(a + l, a + r);
        reverse(ppc + l, ppc + r);
        int cur_m = m;
        if (r - cur_m > cur_m - l) {
            ++cur_m;
        } else if (r - cur_m < cur_m - l) {
            --cur_m;
        }
        relax(l, cur_m, r, 1);
        reverse(a + l, a + r);
        reverse(ppc + l, ppc + r);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ppc[i] = popcount(a[i]);
    }
    solve(0, n);
    cout << ans << endl;
    return 0;
}