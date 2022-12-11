// Megumin

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(101);
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ++a[value];
    }
    int mx = 0;
    int cnt = 0;
    for (int i = 1; i <= 100; ++i) {
        mx = max(mx, a[i]);
        if (a[i]) {
            ++cnt;
        }
    }
    cout << k * ((mx - 1) / k + 1) * cnt - n;
    return 0;
}