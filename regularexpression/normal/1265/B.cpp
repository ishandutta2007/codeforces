#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> l(n, -1), st;
    for (int i = n - 1; i > -1; i--) {
        while (!st.empty() && p[st.back()] < p[i]) {
            l[st.back()] = i;
            st.pop_back();
        }
        st.pb(i);
    }
    st.clear();
    vector<int> r(n, n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && p[st.back()] < p[i]) {
            r[st.back()] = i;
            st.pop_back();
        }
        st.pb(i);
    }
    vector<bool> f(n, 0);
    for (int i = 0; i < n; i++) {
        f[p[i]] = (r[i] - l[i] - 1 >= p[i] + 1 ? 1 : 0);
    }
    for (int i = 0; i < n; i++) {
        cout << f[i];
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}