#include <iostream>

using namespace std;

int x1, y1, x2, y2, dx, dy;

int main()
{
    cin >> x1 >> y1 >> x2 >> y2;
    dx = (x1 < x2 ? x2 - x1 : x1 - x2);
    dy = (y1 < y2 ? y2 - y1 : y1 - y2);
    cout << !!dx + !!dy << " ";
    if ((x1 + y1) % 2 != (x2 + y2) % 2) cout << "0 ";
    else if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2) cout << "1 ";
    else cout << "2 ";
    cout << dx + dy - min(dx, dy);
    return 0;
}