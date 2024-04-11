#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int calc(vector<int>& a, int n) {
    int last = -1;
    int ans = 0;
    for (auto i : a) {
        chkmax(ans, i - last);
        last = i;
    }
    chkmax(ans, n - last);
    ans--;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x - 1].push_back(i);
    }
    vector<int> ans(n + 1, n);
    for (int i = 0; i < n; ++i) {
        int now = calc(pos[i], n);
        //cout << "i = " << i << " now = " << now << endl;
        //cout << "pos[i] = ";
        //for (auto x : pos[i]) cout << x << " ";
        //cout << endl;
        chkmin(ans[now], i);
    }
    for (int i = 1; i < n; ++i) {
        chkmin(ans[i], ans[i - 1]);   
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == n) ans[i] = -1;
        else ans[i]++;
        cout << ans[i] << " ";
    }
    cout << "\n";
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