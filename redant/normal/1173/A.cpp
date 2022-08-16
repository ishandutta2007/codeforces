#include <iostream>

using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    char r = '?';

    if (x > y + z) {
        r = '+';
    } else if (y > x + z) {
        r = '-';
    } else if (x == y && z == 0) {
        r = '0';
    }

    cout << r << endl;

    return 0;
}