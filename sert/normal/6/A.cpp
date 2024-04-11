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

int is3(int a, int b, int c)
{
  if (a < b + c && b < a + c && c < a + b) return 2;
  if (a == b + c || b == a + c || c == a + b) return 1;
  return 0;
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
    int a, b, c, d, ans = 0;
    string s;
    cin >> a >> b >> c >> d;
    ans = max(ans, is3(a, b, c));
    ans = max(ans, is3(a, b, d));
    ans = max(ans, is3(a, d, c));
    ans = max(ans, is3(d, b, c));
    if (ans == 0)
      cout << "IMPOSSIBLE";
    if (ans == 1)
      cout << "SEGMENT";
    if (ans == 2)
      cout << "TRIANGLE";

    return 0;
}