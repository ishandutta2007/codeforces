#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i < b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

int get_sum(int a, int s)
{
  int ans = 0;
  while (a > 0)
  {
    ans += a % s;
    a /= s;
  }
  return ans;
}

int gcd(int a, int b)
{
  if (a % b == 0) return b; else return gcd(b, a % b);
}

void ret(string s)
{
  cout << s;
  exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x, y;
    cin >> x >> y;
    while (1 < 2)
    {
      if (x * 100 + y * 10 < 220 || y < 2)
        ret("Hanako");
      if (x == 0) y -= 22;
      if (x == 1) {x -= 1; y -= 12;}
      if (x >= 2) {x -= 2; y -= 2;}
      if (x * 100 + y * 10 < 220 || y < 2)
        ret("Ciel");
      if (y < 12) {x -= 2; y -= 2;} else
      if (y < 22) {x -= 1; y -= 12;} else
      y -= 22;
    }
    return 0;
}