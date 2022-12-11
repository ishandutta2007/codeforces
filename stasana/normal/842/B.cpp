#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

typedef long double ld;

using namespace std;

int r, d;

ld len(int x, int y) {
    return sqrt(x * x + y * y);
}

bool check(int x, int y, int rr) {
    return !(rr + len(x, y) > r || len(x, y) - rr < r - d);
}

int main() {
    int res = 0;
    cin >> r >> d;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, rr;
        cin >> x >> y >> rr;
        if (check(x, y, rr)) {
            ++res;
        }
    }
    cout << res;
    return 0;
}