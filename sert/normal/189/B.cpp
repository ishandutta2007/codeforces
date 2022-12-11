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

bool _less(char a, char c)
{
  return a > c;
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
    ll h, w, ans = 0;
    cin >> h >> w;
    fab(i, 1, h)
      fab(j, 1, w)
        if (i % 2 == 0 && j % 2 == 0)
          ans += (h - i + 1) * (w - j + 1);
    cout << ans;

}