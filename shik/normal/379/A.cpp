#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0, x = a, y = 0;
    while (x > 0 || y >= b) {
        ans += x;
        y += x;
        x = y / b;
        y %= b;
    }
    cout << ans << endl;
    return 0;
}