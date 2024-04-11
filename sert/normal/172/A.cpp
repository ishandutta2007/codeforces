#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s[30000];
    int n, kol = 0, k;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> s[i];
    int len = s[0].length();
    int i = 1;
    while (i <= len)
    {
      for (int j = 1; j < n; j++)
        if (s[j][kol] != s[j - 1][kol])
        {
          cout << kol;
          return 0;
        }
      i++;
      kol++;
    }
    cout << kol;
    return 0;
}