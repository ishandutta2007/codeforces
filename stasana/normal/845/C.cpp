#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(l, -1);
        a.emplace_back(r, 1);
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < n + n; ++i) {
        cnt -= a[i].second;
        if (cnt > 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}