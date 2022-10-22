#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        int x = a - b;
        if (x == 0) {
            cout << 0 << endl;
        } else if (x > 0) {
            if (x % 2 == 0) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            if (x % 2 == 0) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        }
    }
    return 0;
}