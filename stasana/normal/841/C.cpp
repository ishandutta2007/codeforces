#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), [](int a, int b){return a > b;});
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[a[i].second] = b[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}