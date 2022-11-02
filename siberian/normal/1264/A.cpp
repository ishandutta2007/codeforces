#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n;
    cin >> n;
    int last;
    cin >> last;
    vector<int> ans;
    ans.push_back(1);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        if (x != last)
            ans.push_back(0);
        ans[ans.size() - 1]++;
        last = x;
    }
    if (ans.size() < 3) {
        cout << "0 0 0\n";
        return;
    }
    int g = ans[0];
    int s = ans[1];
    int pos = 2;
    for (int i = 2; i < ans.size(); i++) {
        if (s > g) break;
        s += ans[i];
        pos++;
    }
    if (g + s > n / 2 || pos == ans.size()) {
        cout << "0 0 0\n";
        return;
    }
    int b = ans[pos];
    for (int i = pos + 1; i < ans.size(); i++) {
        if (b + g + s + ans[i] > n / 2) break;
        b += ans[i];
    }
    if (b + g + s > n / 2 || g >= s || g >= b || !g || !s || !b) {
        cout << "0 0 0\n";
        return;
    }
    cout << g << " " << s << " " << b << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}