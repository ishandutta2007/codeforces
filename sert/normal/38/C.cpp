#include <iostream>

using namespace std;

int main()
{
    int a[1000], i, j, k, n, m, rez = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = k; i <= 104; i++)
    {
        m = 0;
        for (j = 1; j <= n; j++)
            m = m + a[j] / i;
        if (m * i > rez) rez = m * i;
    }
    cout << rez << endl;
    return 0;
}