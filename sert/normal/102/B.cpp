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

struct dbl
{
  int a, b;
};

bool _less(dbl a, dbl b)
{
  if (a.a != b.a)
    return a.a < b.a;
  return a.b < b.b;
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
    string s;
    int p, h = 0, kol = 1;
    cin >> s;
    if (s.length() == 1)
    {
      cout << 0;
      return 0;
    }
    fr(i, s.length())
      h += s[i] - '0';
    while (h > 9)
    {
      p = 0;
      while (h > 0)
      {
        p += h % 10;
        h /= 10;
      }
      h = p;
      kol++;
    }
    cout << kol;
    return 0;
}