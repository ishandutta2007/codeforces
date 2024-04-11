#include <iostream>

using namespace std;

int main()
{
    int n, d[128];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    int k;
    for (int i = n; i > 0; i--)
        for (int j = 1; j < i; j++)
            if (d[j-1] < d[j])
            {
                k = d[j];
                d[j] = d[j-1];
                d[j-1] = k;
            }
    int x, y;
    y = d[0];
    k = 1;
    x = d[0];
    bool del = true;
    while (del)
    {
        if (y == d[k])
            del = false;
        else
        {
            y = d[k];
            k++;
            if (x % y != 0)
                del = false;
        }
    }
    cout << x << " " << y;
    return 0;
}