#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        unsigned long long int a;
        cin >> a;

        if (a < 29) {
            if (a > 14 && a < 21) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

            continue;
        }

        if (a % 14 == 0) {
            cout << "NO" << endl;
            continue;
        }

        if (a % 14 < 7) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}