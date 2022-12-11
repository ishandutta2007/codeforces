#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    long long l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (long long i = x; i <= y; ++i) {
        if (l <= i * k && i * k <= r) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}