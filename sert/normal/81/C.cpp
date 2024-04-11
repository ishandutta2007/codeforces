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
    int n, k, p, m = 1, ans[100000] = {0}, pos, p2;
    dbl a[100000];
    cin >> n >> k >> p;
    fr(i, n)
      cin >> a[i].a;
    fr(i, n)
      a[i].b = i;
    if (k == p)
    {
      fr(i, k)
        cout << "1 ";
      fr(i, p)
        cout << "2 ";
      return 0;
    }
    sort(a, a + n, _less);
    if (p <= k)
    {
      fr(i, k)
        ans[a[i].b] = 1;
      fr(i, n)
        if (ans[i] != 0)
          cout << "1 ";
        else
          cout << "2 ";
      return 0;
    }
    else
    {
      fr(i, p)
        ans[a[i].b] = 1;
      m = a[p - 1].a;
      pos = p - 1;
      while(pos >= 0 && a[pos - 1].a == m)
        pos--;
      p2 = p;
      while(a[p2].a == m && p2 < n)
      {
        ans[a[pos].b] = 0;
        ans[a[p2].b] = 1;
        p2++;
        pos++;
      }
      fr(i, n)
        if (ans[i] == 0)
          cout << "1 ";
        else
          cout << "2 ";
    }

    return 0;
}