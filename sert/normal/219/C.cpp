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

string s, h = "AB";
int k, a1 = 0, a2 = 0, ans = 0;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> k >> s;
    if (k == 2)
    {
      fr(i, s.length())
        if (s[i] != h[i % 2]) a1++; else a2++;
      cout << min(a1, a2) << "\n";
      if (a1 < a2)
        fr(i, s.length())
          cout << h[i % 2];
      else
        fr(i, s.length())
          cout << h[(i + 1) % 2];
      return 0;
    }
    s += "@";
    //cerr << s;
    fab(i, 1, s.length() - 2)
      if (s[i] == s[i - 1])
      {
        //cerr << i;
        ans++;
        //cerr << s[i] << " " << s[i + 1] << "\n";
        if (s[i] != 'A' && s[i + 1] != 'A') s[i] = 'A'; else
        if (s[i] != 'B' && s[i + 1] != 'B') s[i] = 'B'; else
        if (s[i] != 'C' && s[i + 1] != 'C') s[i] = 'C';
      }
    cout << ans << "\n";
    fr(i, s.length() - 1)
      cout << s[i];
    return 0;
}