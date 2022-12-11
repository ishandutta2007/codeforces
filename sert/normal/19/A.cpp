#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct team
{
  string name;
  int zg, pg, sc;
};

void ret(string s)
{
  cout << s;
  exit(0);
}

int val(string s)
{
  int ans = 0;
  int n = s.length();
  for (int i = 0; i < n; i++)
    ans = ans * 10 + s[i] - '0';
  return ans;
}

bool _less (team a, team b)
{
  if (a.sc != b.sc)
    return a.sc < b.sc;
  if (a.zg - a.pg != b.zg - b.pg)
    return a.zg - a.pg < b.zg - b.pg;
  return a.zg < b.zg;
}

bool _less1 (team a, team b)
{
  return a.name < b.name;
}

int n, ans = 0, mx, nm, p, t0, t1, sc0, sc1;
team a[100];
string s, s0, s1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i].name;
    for (int i = 0; i < n; i++)
    {
      a[i].sc = 0;
      a[i].zg = 0;
      a[i].pg = 0;
    }
    for (int i = 0; i < (n * (n -1)) / 2; i++)
    {
      cin >> s;
      s0 = "";
      s1 = "";
      p = 0;
      while (s[p] != '-')
      {
        s0 += s[p];
        p++;
      }
      p++;
      while (p < s.length())
      {
        s1 += s[p];
        p++;
      }
      for (int i = 0; i < n; i++)
        if (a[i].name == s0)
          t0 = i;
      for (int i = 0; i < n; i++)
        if (a[i].name == s1)
          t1 = i;
      p = 0;
      s0 = "";
      s1 = "";
      cin >> s;
      while (s[p] != ':')
      {
        s0 += s[p];
        p++;
      }
      p++;
      while (p < s.length())
      {
        s1 += s[p];
        p++;
      }
      sc1 = val(s1);
      sc0 = val(s0);
      a[t0].zg += sc0;
      a[t1].zg += sc1;
      a[t0].pg += sc1;
      a[t1].pg += sc0;
      if (sc0 == sc1) {a[t0].sc += 1; a[t1].sc += 1;}
      if (sc0 > sc1) a[t0].sc += 3;
      if (sc1 > sc0) a[t1].sc += 3;
    }
    sort(a, a + n, _less);
    sort(a + n / 2, a + n, _less1);
    int j = n / 2;
    while (j < n)
    {
      cout << a[j].name;
      printf("\n");
      j++;
    }
    return 0;
}