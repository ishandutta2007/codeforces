#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve(int n, vector<int> left, vector<int> right) {
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = left[i];
        a[i].second = i;
    }
    vector<int> res(n);
    sort(a.begin(), a.end());
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (t > right[a[i].second]) {
            continue;
        }
        t = max(t, a[i].first);
        res[a[i].second] = t;
        ++t;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 0; i < n; ++i) {
            cin >> left[i] >> right[i];
        }
        solve(n, left, right);
    }
}