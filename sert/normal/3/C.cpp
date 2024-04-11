#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct it
{
  int a, n;
};

bool _less (it a, it b)
{
  return a.a < b.a;
}

void ret(string s)
{
  cout << s;
  exit(0);
}

int a[3][3];
int p[8];
int n, kol = 0, r, x = 0, o = 0, xw = 0, ow = 0;
string s;

int main()
{
    for (int i = 0; i < 3; i++)
    {
      cin >> s;
      for (int j = 0; j < 3; j++)
      {
        if (s[j] == '.') a[i][j] = 0;
        if (s[j] == 'X') {a[i][j] = 1; x++;}
        if (s[j] == '0') {a[i][j] = 2; o++;}
      }
    }
    if (x - o > 1 || o > x || o > 4 || x > 5) ret("illegal");
    for (int i = 0; i < 3; i++)
      p[i] = a[i][0] * a[i][1] * a[i][2];
    for (int i = 3; i < 6; i++)
      p[i] = a[0][i - 3] * a[1][i - 3] * a[2][i - 3];
    p[7] = a[0][0] * a[1][1] * a[2][2];
    p[6] = a[2][0] * a[1][1] * a[0][2];
    for (int i = 0; i < 8; i++)
    {
      if (p[i] == 1) xw = 1;
      if (p[i] == 8) ow = 1;
    }
    if (xw * ow == 1) ret("illegal");
    if (xw == 1)
      if (x == o + 1)
        ret("the first player won");
      else
        ret("illegal");
    if (ow == 1)
      if (x == o)
        ret("the second player won");
      else
        ret("illegal");
    if (x + o == 9) ret("draw");
    if (x > o) ret("second");
    ret("first");
    return 0;
}