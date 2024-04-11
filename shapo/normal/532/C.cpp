#include <iostream>
#include <algorithm>

using namespace std;

int
main()
{
    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;
    if (xp <= xv && yp <= yv) {
        cout << "Polycarp" << endl;
    } else if (xp >= xv && yp >= yv) {
        cout << "Vasiliy" << endl;
    } else if (xp + yp <= max(xv, yv)) {
        cout << "Polycarp" << endl;
    } else {
        cout << "Vasiliy" << endl;
    }
    return 0;
}