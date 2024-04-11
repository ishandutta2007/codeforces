#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while ((n % 7) > 0)
    {
        n -= 4;
        count++;
    }
    if (n < 0)
    {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < count; i++)
        cout << 4;
    for (int i = 0; i < n / 7; i++)
        cout << 7;
    cout << "\n";
    //system ("Pause");
}