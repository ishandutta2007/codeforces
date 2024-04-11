#include <bits/stdc++.h>

using namespace std;

void swapEls(int i, int j, vector<int>& a, vector<int>& reva) {
    swap(reva[a[i]], reva[a[j]]);
    swap(a[i], a[j]);
}

bool moveCanBe(int k, int n, int m, vector<int> cyc) {
    vector<int> a(n), elat(n);
    for (int i = 0; i < k; ++i) {
        int ind = i;
        int val = n - k + i;
        a[ind] = val;
        elat[val] = ind;
    }
    for (int i = k; i < n; ++i) {
        int ind = i;
        int val = i - k;
        a[ind] = val;
        elat[val] = ind;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != cyc[i]) {
            --m;
            swapEls(i, elat[cyc[i]], a, elat);
        }
    }

    return (m >= 0);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<int> k(n, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= i) {
            ++k[i - a[i]];
        } else {
            ++k[i + n - a[i]];
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (k[i] * 3 >= n) {
            if (moveCanBe(i, n, m, a)) {
                ans.push_back(i);
            }
        }
    }

    cout << ans.size() << " ";
    for (int ca : ans) {
        cout << ca << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}