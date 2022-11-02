#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> have;
    for (int l = 1; l < n; ++l) {
        if (s[l] == 'W') continue;
        if (s[l - 1] != 'W') continue;
        int r = l;
        while (r < n && s[r] == 'L') ++r;
        if (r == n) break;
        have.push_back(r - l);
        l = r - 1;
    }
    int sum = 0;
    for (auto i : s) {
        sum += i == 'W';
    }
    if (sum == 0) {
        cout << max(0, 2 * k - 1) << "\n";
        return;
    }
    sum += k;
    if (sum == 0) {
        cout << 0 << "\n";
        return;
    }
    int starts = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') continue;
        if (i == 0 || s[i - 1] == 'L') {
            starts++;
        }
    }
    sort(all(have));
    for (auto i : have) {
        if (i <= k) {
            --starts;
            k -= i;
        }
    }
    //cout << sum << " " << starts << endl;
    //exit(0);
    cout << min(2 * n - 1, 2 * sum - starts) << "\n";
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