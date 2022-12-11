#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 34;

void solve() {
    vector<int> p;
    vector<bool> isP(N, true);
    for (int i = 2; i < N; i++) {
        if (!isP[i]) continue;
        p.push_back(i);
        for (int j = i * 2; j < N; j += i) isP[j] = false;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mnP = sqrt(n) + 1;
        cout << upper_bound(p.begin(), p.end(), n) - lower_bound(p.begin(), p.end(), mnP) + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
#ifdef SERT
    int t = 1;
    for (int i = 1; i < t; i++) {
        solve();
    }
#endif
}