#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> cg(2, 0), cf(2, 0);
    vector<int> l0{4, 4, 3, 3, 2, 2, 1, 1, 0, 0};
    vector<int> l1{5, 4, 4, 3, 3, 2, 2, 1, 1, 0};

    for (int i = 0; i < 10; ++i) {
        if (s[i] == '1') {
            ++cg[i & 1];
        } else if (s[i] == '?') {
            ++cf[i & 1];
        }
        if (cg[0] + cf[0] > cg[1] + l1[i] || cg[1] + cf[1] > cg[0] + l0[i]) {
//            cout << cg[0] << ", " << cg[1] << ", " << free << endl;
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << "10\n";
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