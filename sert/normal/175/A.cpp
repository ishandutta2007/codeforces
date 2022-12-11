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
    string s, h1, h2, h3;
    int u1, u2, u3, ans = -1;
    cin >> s;
    int n = s.length();
    if (s.length() < 3) ret("-1");
    fr(i, n - 2)
      fab(j, i + 1, n - 2)
      {
        h1 = "";
        h2 = "";
        h3 = "";
        fr(k, i + 1) h1 += s[k];
        fab(k, i + 1, j) h2 += s[k];
        fab(k, j + 1, n - 1) h3 += s[k];
        if (h1.length() > 6 && h1 != "1000000") continue;
        if (h2.length() > 6 && h2 != "1000000") continue;
        if (h3.length() > 6 && h3 != "1000000") continue;
        if (h1[0] == '0' && h1 != "0") continue;
        if (h2[0] == '0' && h2 != "0") continue;
        if (h3[0] == '0' && h3 != "0") continue;
        u1 = val(h1);
        u2 = val(h2);
        u3 = val(h3);
        ans = max(ans, u1 + u2 + u3);
      }
    cout << ans;
    return 0;
}