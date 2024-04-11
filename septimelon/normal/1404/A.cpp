#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    for (int i = k; i < n; ++i) {
        if (s[i - k] != '?') {
            if (s[i] != '?' && s[i] != s[i - k]) {
                cout << "NO\n";
                return;
            }
            if (s[i] == '?') {
                s[i] = s[i - k];
            }
        }
    }
    for (int i = n - 1; i >= k; --i) {
        if (s[i] != '?') {
            if (s[i - k] != '?' && s[i - k] != s[i]) {
                cout << "NO\n";
                return;
            }
            if (s[i - k] == '?') {
                s[i - k] = s[i];
            }
        }
    }

    vector<int> c(2, 0);
    for (int i = 0; i < k; ++i) {
        if (s[i] != '?') {
            ++c[s[i] - '0'];
        }
    }

    if (c[0] > k / 2 || c[1] > k / 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
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