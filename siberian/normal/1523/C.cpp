#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

string get(vector<int>& st) {
    string ans = "";
    for (int i = 0; i < st.size(); ++i) {
        if (i > 0) {
            ans += '.';
        }
        ans += to_string(st[i]);
    }
    return ans;
}

bool canDown(vector<int>&, int x) {
    return x == 1;
}

bool canSame(vector<int>& st, int x) {
    return st.back() + 1 == x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<int> st;
    vector<string> ans;
    for (int i = 0; i < n; ++i) {
        if (canDown(st, a[i])) {
            st.push_back(a[i]);
        } else {
            while (!st.empty() && !canSame(st, a[i])) {
                st.pop_back();
            }
            assert(!st.empty());
            st[st.size() - 1]++;
        }
        ans.push_back(get(st));
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
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