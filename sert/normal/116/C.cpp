#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    long int a[3000], n, b, p, m, max;
    cin >> n;
    max = 0;
    p = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        max = 1;
        b = i;
        while (a[b] > -1)
        {
            max++;
            b = a[b];
        }
        if (max > p) p = max;
    }
    cout << p;
    return 0;
}