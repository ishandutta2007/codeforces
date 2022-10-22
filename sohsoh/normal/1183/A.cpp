#include <iostream>

using namespace std;

bool isIntresting(int n) {
    int digitSum = 0;
    while (n > 0) {
        digitSum += n % 10;
        n /= 10;
    }

    if (digitSum % 4 == 0)
        return true;

    return false;
}

int main() {
    int n;
    cin >> n;

    while (!isIntresting(n))
        n++;

    cout << n << endl;
    return 0;
}