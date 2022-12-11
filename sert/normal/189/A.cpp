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

struct dv
{
  int a, b;
};

bool les1(dv c, dv d)
{
  return c.a < d.a;
}

bool les2(dv c, dv d)
{
  return c.b > d.b;
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
    int a, b, c, n;
    int u[100000] = {0};
    cin >> n >> a >> b >> c;
    u[a] = 1;
    u[b] = 1;
    u[c] = 1;
    fr(i, n + 1)
    {
      if(i > a) if (u[i - a] != 0) u[i] = max(u[i], u[i - a] + 1);
      if(i > b) if (u[i - b] != 0) u[i] = max(u[i], u[i - b] + 1);
      if(i > c) if (u[i - c] != 0) u[i] = max(u[i], u[i - c] + 1);
    }
    cout << u[n];
    return 0;
}