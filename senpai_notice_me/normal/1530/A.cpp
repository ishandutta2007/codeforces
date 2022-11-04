#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;

        int ans = 0;
        while (x > 0) {
            ans = max(ans, x % 10);
            x /= 10;
        }

        cout << ans << "\n";
    }

    return 0;
}