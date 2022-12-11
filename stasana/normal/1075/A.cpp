// Yunyun loli

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();

    int64_t n;
    int64_t x, y;
    cin >> n >> x >> y;
    if (x + y - 2 <= n - x + n - y) {
        cout << "White" << endl;
    }
    else {
        cout << "Black" << endl;
    }

    return 0;
}