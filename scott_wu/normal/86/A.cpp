#include <iostream>

using namespace std;

long long pow10[11];

long long reverse (long long x, long long dig)
{
     return (long long) (pow10[dig] - 1 - x);
}

int main()
{
    long long l, r;
    cin >> l >> r;
    int ldig = 0, rdig = 0;
    long long temp = l;
    while (temp > 0)
    {
          ldig++;
          temp /= 10;
    }
    temp = r;
    while (temp > 0)
    {
          rdig++;
          temp /= 10;
    }
    pow10[0] = (long long) 1;
    for (int a = 1; a <= 10; a++)
        pow10[a] = (long long) 10 * pow10[a-1];
    if (ldig < rdig)
    {
       ldig = rdig;
       l = pow10[rdig - 1];
    }
    long long best = 5 * pow10[rdig - 1] - 1;
    long long ans = 1;
    if (l <= (best + 1) && best <= r)
       ans = (best) * (best + 1);
    if (l > best + 1)
       ans = l * reverse (l, ldig);
    if (r < best)
       ans = r * reverse (r, rdig);
    cout << ans << "\n";
    /*cout << best << "\n";
    for (int a = 0; a < 11; a++)
        cout << pow10[a] << "\n";
    system ("Pause");*/
    return 0;
}