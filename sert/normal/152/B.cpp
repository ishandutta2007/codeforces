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

void ret(string s)
{
  cout << s;
  exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x, y, vx, vy, m, n, k, kx, ky, kol;
    ll ans = 0;
    cin >> n >> m;
    cin >> x >> y >> k;
    fr(i, k)
    {
      cin >> vx >> vy;
      if (vx == 0) kx = 2000000000;
      if (vx > 0) kx = (n - x) / vx;
      if (vx < 0) kx = (1 - x) / vx;
      if (vy == 0) ky = 2000000000;
      if (vy > 0) ky = (m - y) / vy;
      if (vy < 0) ky = (1 - y) / vy;
      kol = min(kx, ky);
      ans += kol;
      x += vx * kol;
      y += vy * kol;
    }
    cout << ans;
    return 0;
}