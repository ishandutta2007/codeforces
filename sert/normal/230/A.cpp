#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

struct dva
{
  ll x, y;
};

bool _less(dva a, dva b)
{
  return a.x < b.x;
}

void ret(string s)
{
  cout << s;
  exit(0);
}

dva a[200000];
ll n, s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> n;
    fr(i, n) cin >> a[i].x >> a[i].y;
    sort(a, a + n, _less);
    fr(i, n)
    {
      if (a[i].x >= s) ret("NO");
      s += a[i].y;
    }
    cout << "YES";
    return 0;
}