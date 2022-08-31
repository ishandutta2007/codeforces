#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x == 1)
    {
        if (y == 1)
            cout << "=";
        else
            cout << "<";
    }
    else if (y == 1)
    {
        cout << ">";
    }
    else {
    
    x = x - 3;
    y = y - 3;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    
    if (x < y) cout << ">";
    else if (x > y) cout << "<";
    else cout << "=";}
}