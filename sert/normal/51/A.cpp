#include <iostream>

using namespace std;

bool same(string s, string k)
{
  bool ok = false;
  s += s[0];
  s += s[1];
  s += s[2];
  for(int i = 0; i <= 3; i++)
    if(k[0] == s[i] && k[1] == s[i + 1] && k[2] == s[i + 2] && k[3] == s[i + 3])
      ok = true;
  return ok;
}

int main()
{
    string s, a[1000];
    int n, kol = 0;
    bool ok = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i] >> s;
      a[i] += s[1];
      a[i] += s[0];
      cin >> s;
    }
    for (int i = 0; i < n; i++)
    {
      ok = false;
      for (int j = 0; j < i; j++)
        if (same(a[i], a[j]))
          ok = true;
      if(!ok)
        kol++;
    }
    cout << kol;
    return 0;
}