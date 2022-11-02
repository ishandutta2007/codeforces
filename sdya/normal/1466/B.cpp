#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set < int > S;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] == a[i - 1]) {
            ++a[i];
        } else if (i + 1 < n && a[i] + 1 < a[i + 1]) {
            ++a[i];
        } else if (i == n - 1) {
            ++a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        S.insert(a[i]);
    }
    cout << S.size() << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }


    return 0;
}