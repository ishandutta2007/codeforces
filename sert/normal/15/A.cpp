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

it a[10000];
int n, kol = 0, r;

int main()
{
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i].a;
      cin >> a[i].n;
    }
    sort(a, a + n, _less);
    for (int i = 1; i < n; i++)
    {
      if (r * 2 <= 2 * (a[i].a - a[i - 1].a) - a[i].n - a[i - 1].n) kol++;
      if (r * 2 < 2 * (a[i].a - a[i - 1].a) - a[i].n - a[i - 1].n) kol++;
    }
    cout << kol + 2;
    return 0;
}