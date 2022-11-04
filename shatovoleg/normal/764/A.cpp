#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n, m, z;
    cin >> n >> m >> z;
    cout << z / (n / gcd(n, m) * m) << endl;
}