#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct h
{
  int a, n;
};

void ret(string s)
{
  cout << s;
  exit(0);
}

bool _less (h a, h b)
{
  return a.a < b.a;
}

int k, n, ans = 0, mx, nm, p, t0, t1, sc0, sc1;
int u2[100] = {0}, u[100] = {0};
h a[100];
string s, s0, s1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    cin >> k;
    if (k >= s.length())
    {
      printf("0\n");
      ret("");
    }
    for (int i = 0; i < 26; i++)
      {a[i].n = i; a[i].a = 0;}
    for (int i = 0; i < s.length(); i++)
      a[s[i] - 'a'].a++;
    sort(a, a + 26, _less);
    for (int i = 0; i < 26; i++)
      if (a[i].a <= k)
      {
        k -= a[i].a;
        u[a[i].n] = 1;
      }
    for (int i = 0; i < s.length(); i++)
      if (u[s[i] - 'a'] == 0 && u2[s[i] - 'a'] == 0) {ans++; u2[s[i] - 'a'] = 1;}
    printf("%d\n", ans);
    for (int i = 0; i < s.length(); i++)
      if (u[s[i] - 'a'] == 0)
        cout << s[i];
    return 0;
}