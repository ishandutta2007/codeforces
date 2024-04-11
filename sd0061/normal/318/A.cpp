#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  long long n , k , m;
  cin >> n >> k;
  m = n + 1; m >>= 1;
  if (k <= m)
    cout << k + k - 1;
  else cout << (k - m) * 2;
  return 0;
}