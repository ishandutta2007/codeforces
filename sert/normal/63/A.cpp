#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct db
{
  string a, b;
  int n;
};

bool _less(db a, db b)
{
  int aa, bb;
  if (a.b == "rat")
    aa = 0;
  if (a.b == "woman" || a.b == "child")
    aa = 1;
  if (a.b == "man")
    aa = 2;
  if (a.b == "captain")
    aa = 3;
  if (b.b == "rat")
    bb = 0;
  if (b.b == "woman" || b.b == "child")
    bb = 1;
  if (b.b == "man")
    bb = 2;
  if (b.b == "captain")
    bb = 3;
  if (aa == bb)
    return a.n < b.n;
  else
    return aa < bb;
}

db a[1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i].a >> a[i].b;
      a[i].n = i;
    }
    sort(a, a + n, _less);
    for (int i = 0; i < n; i++)
      {
        cout << a[i].a;
        printf("\n");
      }
    return 0;
}