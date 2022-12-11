#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

ll p, d, v, ans, t, st = 1, a;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> p >> d;
    a = p;
    ans = p;
    v = 0;
    t = 1;
    while(p - a <= d)
    {
      while ((a % (st * 10)) / st != 9 && p - a <= d)
      {
        a -= st;
      }
      if (p - a <= d) ans = a;
      st *= 10;
    }
    cout << ans;
    return 0;
}