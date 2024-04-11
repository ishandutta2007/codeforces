#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        int qwer;
        cin >> qwer;
        m += qwer;
        k -= min(m, 8);
        m = max(0, m - 8);
        if (k <= 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}