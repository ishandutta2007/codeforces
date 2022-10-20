#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
using P = pair<int, int>;

class segtree {
private:
    int n;
    vector<int> tr;
    const int ex = 0;

    int q(int s, int t, int k, int l, int r) {
        return r <= s || t <= l ? ex : s <= l && r <= t ? tr[k]
                : max(q(s, t, k << 1 | 1, l, (l + r) >> 1), q(s, t, (k + 1) << 1, (l + r) >> 1, r));
    }

public:
    segtree(int m) {
        n = 1;
        while (n < m) n <<= 1;
        tr.clear();
        tr.resize((n << 1) - 1, ex);
    }
    void update(int j, const int& x) {
        int i = j + n - 1;
        tr[i] = x;
        while (i > 0) { i = (i - 1) >> 1; tr[i] = max(tr[i << 1 | 1], tr[(i + 1) << 1]); }
    }
    int at(int j) {
        int i = j + n - 1;
        return tr[i];
    }
    // [s, t)
    int run(int s, int t) { return q(s, t, 0, 0, n); }
};


vector<int> compress(const vector<int>& a) {
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < (int)b.size(); ++i) {
        mp[b[i]] = i;
    }
    vector<int> res(a.size());
    for (int i = 0; i < (int)res.size(); ++i) {
        res[i] = mp[a[i]];
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a = compress(a);
        int m = -1;
        for (int i = 0; i < n; ++i) {
            m = max(m, a[i] + 1);
        }
        segtree sg(m);
        stack<P> st;
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int s = sg.run(a[i], m) + 1;
            while (!st.empty()) {
                P p = st.top();
                if (p.first > a[i]) break;
                if (p.first == a[i]) {
                    s = max(s, p.second + 1);
                }
                sg.update(p.first, max(sg.at(p.first), p.second + 1));
                st.pop();
            }
            if (!st.empty()) {
                s = max(s, st.top().second + 1);
            }
            ans = max(ans, s);
            st.emplace(a[i], s);
        }
        ans = max(ans, sg.run(0, m));
        cout << ans << '\n';
    }
    return 0;
}