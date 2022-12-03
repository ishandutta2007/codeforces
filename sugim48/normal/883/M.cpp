#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b == d) {
        swap(a, b);
        swap(c, d);
    }
    int ans = 0;
    if (a == c) {
        ans = 4 + 2*(abs(b-d)+1);
    } else {
        ans = 2*(abs(a-c)+1) + 2*(abs(b-d)+1);
    }
    cout << ans << endl;
    return 0;
}