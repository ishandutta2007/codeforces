#include <iostream>

using namespace std;

int main()
{
    int n, mx = -1000000, mn = 100000000;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        if (v > mx)
            mx = v;
        if (v < mn)
            mn = v;
    }
    cout << (mx + mn) / 2 << endl;
}