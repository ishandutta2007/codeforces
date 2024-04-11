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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x1, x2, y1, y2, n;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if (x1 * x2 == 0 && x1 + x2 == n)
      cout << min(n + y1 + y2, 3 * n - y1 - y2);
    else
      if (y1 * y2 == 0 && y1 + y2 == n)
        cout << min(n + x1 + x2, 3 * n - x1 - x2);
      else
        cout << abs(x1 - x2) + abs(y1 - y2);
    return 0;
}