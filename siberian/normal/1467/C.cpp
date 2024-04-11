#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n[3];
vector<int> a[3];

void read() {
    for (int it = 0; it < 3; ++it) {
        cin >> n[it];
    }
    for (int it = 0; it < 3; ++it) {
        a[it].resize(n[it]);
        for (auto& x : a[it]) {
            cin >> x;
        }
    }
}

ll ans;

void run() {
    ans = -LONG_LONG_MAX;
    ll sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (auto x : a[i]) {
            sum += x;
        }
    }
    for (int i = 0; i < 3; ++i) {
        ll mySum = 0;
        for (auto x : a[i]) {
            mySum += x;
        }
        chkmax(ans, sum - mySum * 2LL);
    }
    vector<int> have;
    for (int i = 0; i < 3; ++i) {
        have.push_back(*min_element(all(a[i])));
    }
    sort(all(have));
    chkmax(ans, sum - 2LL * (have[0] + have[1]));
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}