#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int res = 0;
    while (a != b) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        ++res;
    }
    if ((1 << res) == n) {
        cout << "Final!";
    } else {
        cout << res;
    }
    return 0;
}