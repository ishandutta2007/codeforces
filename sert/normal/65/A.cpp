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

void ret(string s)
{
  cout << s;
  exit(0);
}

int val(string s)
{
  int ans = 0;
  fr(i, s.length())
    ans = ans * 10 + s[i] - '0';
  return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if(e * c * a == 0)
    {
      if (c == 0 && d != 0) ret("Ron");
      if (d == 0 || b == 0) ret("Hermione");
      if (a == 0) ret("Ron");
      if (f == 0) ret("Hermione");
      ret("Ron");
    }
    if (e * c * a >= b * f * d) ret("Hermione");
    cout << "Ron";
    return 0;
}