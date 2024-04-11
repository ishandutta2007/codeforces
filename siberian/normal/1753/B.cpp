#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull  = unsigned long long;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
    if (y < x) {
        x = y;
    }
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) {
        x = y;
    }
}

const int N = 5e5 + 228;
int n, x;
int cnt[N];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> x;
    fill(cnt, cnt + x + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cnt[val]++;
    }
    for (int i = 1; i < x; ++i) {
        if (cnt[i] % (i + 1)) {
            cout << "No\n";
            return 0;
        } else {
            cnt[i + 1] += cnt[i] / (i + 1);
        }
    }
    cout << "Yes\n";
    return 0;
}