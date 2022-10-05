#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> st;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        st.insert(a[i]);
    }
    vector<int> stk;
    stk.push_back(sum);
    while (!stk.empty()) {
        if (st.find(stk.back()) == st.end()) {
            if (stk.back() == 1) {
                cout << "NO\n";
                return;
            } else{
                int x = stk.back();
                stk.pop_back();
                stk.push_back(x / 2);
                stk.push_back((x + 1) / 2);
            }
        } else {
            st.erase(st.find(stk.back()));
            stk.pop_back();
        }
    }
    if (st.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}