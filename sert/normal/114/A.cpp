#include <iostream>

using namespace std;

int main()
{
    long long n, k, kol = -1;
    cin >> n >> k;
    while (k > 1)
    {
      if (k % n != 0)
      {
        cout << "NO";
        return 0;
      }
      k /= n;
      kol++;
    }
    cout << "YES" << endl;
    cout << kol;
    return 0;
}