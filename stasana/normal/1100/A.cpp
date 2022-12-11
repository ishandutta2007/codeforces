// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i < k; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if ((j - i) % k == 0) {
                continue;
            }
            sum += a[j];
        }
        res = max(res, abs(sum));
    }
    cout << res << endl;
}

int main() {
    start();
    solve();
    return 0;
}