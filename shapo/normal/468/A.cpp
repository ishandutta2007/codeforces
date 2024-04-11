#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 5) {
        cout << "YES\n";
        cout << "5 - 1 = 4\n4 - 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
    } else if (n == 4 || n >= 6) {
        cout << "YES\n";
        if (n == 4) {
            cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
        } else {
            cout << "2 * 3 = 6\n6 * 4 = 24\n";
            cout << "6 - 1 = 5\n5 - 5 = 0\n";
            for (int i = 7; i <= n; ++i) {
                cout << "0 * " << i << " = 0\n";
            }
            cout << "0 + 24 = 24\n";
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}