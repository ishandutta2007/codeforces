#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

int nod(int a, int b)
{
  if (a % b == 0) return b;
  else return nod(b, a % b);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, x, y, xx, yy;
    cin >> n >> k >> x;
    int i = 0;
    while (1 < 2)
    {
      if (i % 2 == 0)
      {
        if (x == 0)
        {
          cout << 1;
          return 0;
        }
        y = nod(n, x);
        x -= y;
      }
      else
      {
        if (x == 0)
        {
          cout << 0;
          return 0;
        }
        y = nod(k, x);
        x -= y;
      }
      i++;
    }
}