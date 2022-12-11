#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s, k;
    cin >> s >> k;
    int a[100] = {0};
    int b[100] = {0};
    int kol = 0;
    if (s.length() != k.length())
    {
      cout << "NO";
      return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] != k[i])
      {
        kol++;
        if (kol > 2)
        {
          cout << "NO";
          return 0;
        }
        a[kol] = s[i];
        b[kol] = k[i];
      }
    }
    if (kol == 2 && a[1] == b[2] && a[2] == b[1])
      cout << "YES";
    else
      cout << "NO";
    return 0;
}