#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int res = x;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a < x) {
            --res;
        }
        if (a == x) {
            ++res;
        }
    }
    cout << res;
    return 0;
}