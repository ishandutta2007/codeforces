#include <iostream>

using namespace std;

int main()
{
    int n, a, b, x, y;
    cin >> n >> a >> x >> b >> y;
    while (a > 0 && b > 0) {
        if (a != x) {
            a++;
            if (a > n) a = 1;
        }
        else a = -10000;
        if (b != y) {
            b--;
            if (b < 1) b = n;
        }
        else b = -1000000;
        if (a == b) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}