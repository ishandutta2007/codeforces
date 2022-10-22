#include <iostream>

using namespace std;

int abs(int n) {
    if (n < 0)
        n *= -1;

    return n;
}

int main()
{
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int t;
            cin >> t;

            if (t == 1) {
                cout << abs(i - 3) + abs(j - 3);
                break;
            }
        }
    }
    return 0;
}