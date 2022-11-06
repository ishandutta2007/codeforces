#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k, a, b;
    cin >> k >> a >> b;
    if (a < b)
        swap(a, b);
    if (a < k)
    {
        cout << -1 << endl;
        return 0;
    }
    if (a % k != 0 && b < k)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << a / k + b / k << endl;
}