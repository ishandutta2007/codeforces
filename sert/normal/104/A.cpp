#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 10 || n > 21)
    {
      cout << 0;
      return 0;
    }
    if (n <= 19 || n == 21)
    {
      cout << 4;
      return 0;
    }
    cout << 15;
    return 0;
}