#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

//#define for(i, n) for(int i = 0; i < n; i++)
#define fab(i, a, b) for(int i = a; i < b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int a[100000], m, kol = 0, sum, k, i, u[10000] = {0},ab = 1;
int n;
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    i = 0;
    while (1 < 2)
    {
      i++;
      for (int j = 0; j < n; j++)
        if (a[j] == i)
          u[j] = 1;
      if (u[0] == 1 || u[n - 1] == 1)
      {
        cout << i;
        return 0;
      }
      for (int j = 1; j < n; j++)
        if (u[j] * u[j - 1] == 1)
        {
          cout << i;
          return 0;
        }
    }
    return 0;
}