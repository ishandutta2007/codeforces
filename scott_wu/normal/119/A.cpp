#include <iostream>

using namespace std;

int gcf (int a, int b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    while (true)
    {
        if (n == 0)
        {
            cout << 1 << "\n";
            return 0;
        }
        n -= gcf (a, n);
        if (n == 0)
        {
            cout << 0 << "\n";
            return 0;
        }
        n -= gcf (b, n);
    }
}