#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    long int a, n, b, p, m, max;
    cin >> n;
    max = 0;
    p = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        cin >> b;
        p = p - a + b;
        if (p > max) max = p;
    }
    cout << max;
    return 0;
}