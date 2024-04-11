#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1000007;

void solve(const vector<int>& p) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = 1;
        while (x != 1) {
            int q = p[x];
            if (a[i] % q == 0)
                a[i] /= q;
            else
                a[i] *= q;
            x /= q;
        }
    }

    map<int, int> m;
    for (int t : a)
        ++m[t];

    int res0 = 0, z = 0;
    for (auto& [x, cnt] : m) {
        res0 = max(res0, cnt);
        if (cnt % 2 == 0 || x == 1)
            z += cnt;
    }
    int res1 = max(res0, z);

    int q;
    cin >> q;
    while (q--) {
        ll w;
        cin >> w;
        if (w == 0)
            cout << res0 << "\n";
        else
            cout << res1 << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> p(MAX);
    iota(p.begin(), p.end(), 0);
    for (int i = 2; i < MAX; ++i) {
        if (p[i] == i) {
            for (int j = i + i; j < MAX; j += i)
                p[j] = min(p[j], i);
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve(p);
    return 0;
}