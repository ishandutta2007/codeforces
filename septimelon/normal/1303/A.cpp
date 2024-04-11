#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int l1 = 1000;
    int r1 = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            l1 = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '1') {
            r1 = i;
            break;
        }
    }
    int count0 = 0;
    for (int i = l1; i < r1; ++i) {
        if (s[i] == '0') {
            ++count0;
        }
    }
    cout << count0 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}