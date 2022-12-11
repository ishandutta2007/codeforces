#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> a(1000);
    a[0] = true;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = x + 1; j <= y; ++j) {
            a[j] = true;
        }
    }
    for (int i = 0; i <= m; ++i) {
        if (!a[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}