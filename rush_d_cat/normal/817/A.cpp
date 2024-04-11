#include <iostream>
using namespace std;
int x1, x2, y1, y2, x, y;
int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int ok = 1;
    if(!(dx % x == 0 && dy % y == 0)) {
        ok = 0;
    }
    if(!( (dy / y) % 2 == (dx / x) % 2 ) ) {
        ok = 0;
    }

    printf("%s\n", ok?"YES":"NO");
}