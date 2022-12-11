#include <iostream>

using namespace std;

int main()
{
    int k = 0, n, p = 1, i;
    cin >> n;
    for (i = 1; i < n; i++)
    {
        k++;
        p = (p + k - 1) % n + 1;
        cout << p << " ";
    }
}