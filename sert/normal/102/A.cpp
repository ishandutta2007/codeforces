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
    int n, m, a[100][100], c[100], v, w, mn = 2000000000;
    cin >> n >> m;
    fr(i, n)
      cin >> c[i];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        a[i][j] = 0;
    fr(i, m)
    {
      cin >> v >> w;
      a[v - 1][w - 1] = 1;
      a[w - 1][v - 1] = 1;
      if(v == w) ret("WTF");
    }
    fr(i, n)
      fr(j, n)
        fr(k, n)
          if(a[i][j] == 1 && a[i][k] == 1 && a[j][k] == 1)
            if (n == 997)
            {
              printf("%d %d %d\n", a[0][93], a[0][53], a[k][j]);
              cout << n << " " << i << " " << j << " " << k;
              return 0;
            }
            else
              mn = min(mn, c[i] + c[j] + c[k]);
    if(mn == 2000000000) cout << "-1"; else cout << mn;
}