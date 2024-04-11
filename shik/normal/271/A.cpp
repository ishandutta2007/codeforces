#include <iostream>
using namespace std;

bool good(int y) {
    bool v[10] = {};
    while (y) {
        int d = y % 10;
        if (v[d]) return false;
        v[d] = true;
        y /= 10;
    }
    return true;
}

int main() {
    int y;
    cin >> y;
    y++;
    while (!good(y)) y++;
    cout << y << endl;
    return 0;
}