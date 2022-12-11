#include <iostream>

using namespace std;

long long step (long long n)
{
  if (n == 0)
    return 1;
  if (n % 2 == 0)
  {
    long long p = step(n / 2);
    return (p * p) % 1000000007;
  }
  return (step(n - 1) * 2) % 1000000007;
}

int main()
{
    long long k, ans;
    cin >> k;
    k = step(k);
    ans = (((k + 1) * k) / 2) % 1000000007;
    cout << ans;
    return 0;
}