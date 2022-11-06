#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int a, b;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        b = 100 - a;
        int d = gcd(a, b);
        a /= d;
        b /= d;
        cout << a + b << '\n';
    }

    return 0;
}