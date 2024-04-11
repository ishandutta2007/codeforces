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
    int n, ans = -1, xc, k = 0, m, yc, a, x, y;
    cin >> a >> x >> y;
    xc = 0;
    yc = a;

    fab(i, 1, 1500000)
    {
      if (i > 1){
      if(i % 3 == 0)
      {
        yc = a + (i / 3) * 4 * a;
        xc = -a;
      }
      if(i % 3 == 1)
      {
        yc = a + (i / 3) * 4 * a;
        xc = a;
      }
      if(i % 3 == 2)
      {
        yc = 3 * a + (i / 3) * 4 * a;
        xc = 0;
      }}
      if(abs(2 * x - xc) < a && abs(2 * y - yc) < a)
        ans = i;
    }
    cout << ans;
    return 0;
}