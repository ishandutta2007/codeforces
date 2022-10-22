#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int sum = 0;

        int r, g, b;
        cin >> r >> g >> b;

        if (g < b)
            swap(g, b);
        if (r < b)
            swap(r, b);
        if (r < g)
            swap(r, g);

        int t = r - g;
        if (t > b)
            t = b;

        g += t;
        b -= t;

        t = b / 2;
        g += t;
        r += t;

        cout << min(r, g) << endl;
    }
    return 0;
}