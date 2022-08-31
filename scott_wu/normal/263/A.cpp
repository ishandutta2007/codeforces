#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int x, y;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int t; cin >> t;
            if (t) x = i, y = j;
        }
    }
    cout << abs (x - 2) + abs (y - 2) << "\n";
}