#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check(int h, int m) {
    return h % 10 == 7 || m % 10 == 7;
}

int main() {
    int x;
    cin >> x;
    int h, m;
    cin >> h >> m;
    int res = 0;
    while (!check(h, m)) {
        ++res;
        m -= x;
        if (m < 0) {
            --h;
            m += 60;
        }
        if (h < 0) {
            h = 23;
        }
    }
    cout << res;
    return 0;
}