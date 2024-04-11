#include <iostream>

using namespace std;

int mAbs(int n) {
    if (n < 0) {
        n *= -1;
    }

    return n;
}

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x = mAbs(x1 - x2), y = mAbs(y1 - y2);

    if (y > x) {
        int t = x;
        x = y;
        y = t;
    }

    cout << y + (x - y) << endl;
    return 0;
}