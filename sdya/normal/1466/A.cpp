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
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            S.insert(a[j] - a[i]);
        }
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