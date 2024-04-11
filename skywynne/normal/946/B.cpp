#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, r, t, a, b, p, c, A[N];
int main()
{
    cin >> a >> b;
    while (a != 0 && b != 0)
    {
        if (a >= 2 * b)
        {
            a -= (a / (2 * b)) * 2 * b;
            continue;
        }
        if (b >= 2  *a)
        {
            b -= (b / (2 * a)) * 2 * a;
            continue;
        }
        break;
    }
    cout << a << " " << b;
    return (0);
}