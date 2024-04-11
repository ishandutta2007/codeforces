#include <iostream>

using namespace std;

int nextOne(int n, int k) {
    int remain = k - n % k;
    return n + remain;
}

int main()
{
    long y, k, n;
    cin >> y >> k >> n;

    int fY = y;

    int counter = 0;

    while (nextOne(y, k) <= n) {
        y = nextOne(y, k);
        cout << y - fY << " ";

        counter++;
    }

    if (counter <= 0)
        cout << "-1" << endl;
    return 0;
}