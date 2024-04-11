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
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i].a;
      a[i].n = i + 1;
    }
    sort(a, a + n, _less);
    if ((a[0].a + a[n - 1].a) % 2 == 1) ret("Unrecoverable configuration.");
    if (a[0].a == a[n - 1].a) ret("Exemplary pages.");
    for (int i = 1; i < n - 1; i++)
      if (a[i].a != (a[0].a + a[n - 1].a) / 2) ret("Unrecoverable configuration.");
    cout << (a[n - 1].a - a[0].a) / 2 << " ml. from cup #" << a[0].n << " to cup #" << a[n - 1].n <<".";
    return 0;
}