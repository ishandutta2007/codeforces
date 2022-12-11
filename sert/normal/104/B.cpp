#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++)
    {
      cin >> k;
      sum += 1 + i * (k - 1);
    }
    cout << sum;
  return 0;
}