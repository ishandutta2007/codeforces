#include <iostream>

using namespace std;

int n, ans, p, q;

int main() {
    cin >> n;
    while (n--) {
        cin >> p >> q;
        ans += (q >= p + 2);
    }
    cout << ans;
    return 0;
}