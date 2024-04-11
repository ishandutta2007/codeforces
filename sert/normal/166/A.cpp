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

struct dva
{
  int a, b;
};

bool _less(dva a, dva b)
{
  if (a.a == b.a)
    return a.b < b.b;
  return a.a > b.a;
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
    dva a[100];
    int n, k, l, r;
    cin >> n >> k;
    fab(i, 1, n + 1)
      cin >> a[i].a >> a[i].b;
    sort(a + 1, a + n + 1, _less);
    l = k;
    a[0].a = 100000;
    a[0].b = 100000;
    a[n + 1].a = 100000000;
    a[n + 1].b = 100000000;
    while(a[l].a == a[l - 1].a && a[l].b == a[l - 1].b)
      l--;
    r = k;
    while(a[r].a == a[r + 1].a && a[r].b == a[r + 1].b)
      r++;
    cout << r - l + 1;
    return 0;
}