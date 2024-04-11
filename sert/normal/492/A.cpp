#include <iostream>

using namespace std;

int cur, sum, n;

int main() {
    cin >> n;
    for (int i = 0; true; i++) {
        sum += cur += (i + 1);
        if (sum > n) {
            cout << i;
            return 0;
        }
    }
    return 0;
}