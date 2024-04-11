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
    int n, k = 1, ch = 1;
    cin >> n;
    if (n == 1){cout << "YES"; return 0;}
    while (ch < n)
    {
      k++;
      ch = (k + 1) * k / 2;
      if (ch == n) ret("YES");
    }
    cout << "NO";
    return 0;
}