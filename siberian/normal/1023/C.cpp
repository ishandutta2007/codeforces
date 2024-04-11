#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
  string a;
  int n, k;
  cin >> n >> k;
  cin >> a;
  vector <int> g(n);
  int num = 0;
  for (int i = 0; i < n; i++)
  {
    if (num == (n - k) / 2)
    {
      break;
    }
    if (a[i] == '(')
    {
      g[i] = 1;
      num++;
    }


  }
  num = 0;
    for (int i = 0; i < n; i++)
  {
    if (num == (n - k)/2)
    {
      break;
    }
   
    if (a[i] == ')')
    {
      g[i] = 1;
      num++;
    }

   
  }

  for (int i = 0; i < n; i++)
  {
    if (g[i] == 0)
    {
      cout << a[i];
    }
  }
  return 0;
}