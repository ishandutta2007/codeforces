#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, m;
vector<int> k, c;

// bool check(int cnt) {
//     if (cnt > m) return false;
//     int ptr = 0;
//     for (int i = n - cnt; i < n; ++i) {
//         if (ptr <= k[i]) {
//             ++ptr;
//         } else {
//             return false;
//         }
//     }
//     return true;
// }

// int solve(int cnt) {
//     int ans = 0;
//     assert(cnt <= m);
//     for (int i = 0; i < cnt; ++i) {
//         ans += c[i];
//     }
//     for (int i = 0; i < n - cnt; ++i) {
//         ans += c[k[i]];
//     }
//     return ans;
// }

void solve() {
    // int n, m;
    cin >> n >> m;
    // vector<int> k(n);
    k.resize(n);
    for (auto& i : k) {
        cin >> i;
        --i;
    }
    sort(all(k));
    // vector<int> c(m);
    c.resize(m);
    for (auto& i : c) {
        cin >> i;
    }
    // int ptr = 0;
    // int ans = 0;
    // for (auto i : k) {
    //     if (ptr <= i) {
    //         ans += c[ptr++];
    //     } else {
    //         ans += c[i];
    //     }
    // }
    // int l = 0, r = n + 1;
    // while (l < r - 1) {
    //     int mid = (l + r) / 2;
    //     if (check(mid)) {
    //         l = mid;
    //     } else {
    //         r = mid;
    //     }
    // }
    // cerr << "l = " << l << endl;
    // int ans = solve(l);
    int cnt = n;
    reverse(all(k));
    int sum = 0;
    for (auto i : k) {
        sum += c[i];
    }
    int ans = sum;
    int ptr = 0;
    for (auto i : k) {
        if (cnt == 0) break;
        sum -= c[i];
        sum += c[ptr++];
        chkmin(ans, sum);
        --cnt;
        chkmin(cnt, i);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}