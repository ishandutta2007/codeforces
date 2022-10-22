#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
LL a , b;

void work()
{
  LL i , p;
  cin >> a >> b;
  for (i = 1 ; i <= b ; i *= 10); i /= 10;
  p = i * 10 - 1;
  a = max(a , i);
  if (b >= p / 2 && a <= p / 2)
    cout << p / 2 * (p / 2 + 1);
  else if (b < p / 2)cout << b * (p - b);
  else cout << a * (p - a);
}

int main()
{
  work();
  return 0;
}